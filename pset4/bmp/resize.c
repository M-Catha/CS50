/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }
    
    // Ensure n is the proper size
    int n = atoi(argv[1]);
    if (n < 0 || n > 100) {
        printf("Please use an n factor > 0 and <= 100\n");
        return 1;
    }

    // remember filenames
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    int inWidth = bi.biWidth;
    int inHeight = bi.biHeight;
    int outWidth = (bi.biWidth) * n;
    int outHeight = (bi.biHeight) * n;
    
     // determine padding for scanlines
    int inPadding =  (4 - (inWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int outPadding =  (4 - (outWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    
    // determine out image size and out file size
    bi.biSizeImage = ((outWidth * 3) + outPadding) * abs(outHeight);
    bf.bfSize = bi.biSizeImage + 54;
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    
    // write outfile's BITMAPINFOHEADER
    bi.biHeight = outHeight;
    bi.biWidth = outWidth;
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);


    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(inHeight); i < biHeight; i++) {
        
        int verticalIterator = 0;
        while (verticalIterator < n) {
        // iterate over pixels in scanline
            for (int j = 0; j < inWidth; j++) {
                
                // temporary storage
                RGBTRIPLE triple;
                
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
            
                // write RGB triple to outfile
                for (int k = 0; k < n; k++) {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
                
            }
            
                // skip over padding, if any
                fseek(inptr, inPadding, SEEK_CUR);
                    
                // add padding to end of line in outfile
                for (int x = 0; x < outPadding; x++) {
                    fputc(0x00, outptr);
                }
                
                // send cursor back to beginning of infile line
                if (verticalIterator < n - 1) {
                    int lineWidthInBytes = ((inWidth * 3) + inPadding) * -1;
                    fseek(inptr, lineWidthInBytes, SEEK_CUR);
                }
                
                verticalIterator++;
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}