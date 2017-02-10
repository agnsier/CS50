/**
Your program should accept exactly three command-line arguments, whereby

the first (n) must be a positive integer less than or equal to 100,

the second must be the name of a BMP to be resized, and

the third must be the name of the resized version to be written.
*/
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage,
    int n = atoi(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./copy infile outfile\n");
        return 1;
    }
    if ( n < 1 || n > 100 )
    {
        fprintf(stderr, "n must be a positive integer less than or equal to 100");
        return 1;
    }
// open input file 
    FILE *inptr = fopen(argv[2], "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
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
    // modify data of headers necessary to resize the file
    int originalWidth = bi.biWidth;
    // determine original padding for scanlines
    int originalPadding =  (4 - (originalWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    //determine new dimensions
    bi.biWidth  *= n;
    bi.biHeight *= n;
    // Determine paddings
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) %4) % 4;
    // biSizeImage = width * height * 3 bytes pp + (padding per line)
    bi.biSizeImage = (bi.biWidth * abs(bi.biHeight) * 3) + padding*abs(bi.biHeight);
    // change the file size to reflect the new file size
    bf.bfSize = bi.biSizeImage + bf.bfOffBits;


    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < originalPadding; j++)
        {
        
            // temporary storage
            RGBTRIPLE triple;
            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // write RGB triple to outfile, multiplied by factor

            
            for (int l = 0; l < n; l++)
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);    
        }
         // skip over padding, if any
        fseek(inptr, originalPadding, SEEK_CUR);
            
        
            // Add a new padding
        for (int l = 0; l < padding; l++)
            fputc(0x00, outptr);
            
        // if i % n is 0, write a new row, else repeat the last row
        long offset = originalWidth*sizeof(RGBTRIPLE) + originalPadding;
        if((i+1) % n != 0)
            fseek(inptr, -offset, SEEK_CUR);
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}