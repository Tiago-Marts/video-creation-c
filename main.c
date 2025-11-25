#include <stdio.h>

int main(void){
    //Informações do tamanho da imagem (Default: 960x540)
    const int width = 16 * 60;
    const int height = 9 * 60;
    const int fps = 30;

    char buf[256];

    printf("Generanting video at %dfps...\n", fps);
    for(int i = 0; i < fps; i++){
        snprintf(buf, sizeof(buf), "output-%02d.ppm", i);
        const char* output_path = buf;
        FILE *f = fopen(output_path, "wb");
    
        //Especificação PPM
        fprintf(f, "P6\n");
        fprintf(f, "%d\n", width);
        fprintf(f, "%d\n", height);
        fprintf(f, "255\n");
    
        //Raster
        for(int y = 0; y < height; y++){
            for(int x = 0; x < width; x++){
                if(((x+i)/60 + (y+i)/60)%2){
                    fputc(0xFF,f);
                    fputc(0xFF,f);
                    fputc(0xFF,f);
                } else {
                    fputc(0x00,f);
                    fputc(0x00,f);
                    fputc(0x00,f);
                }
    
            }
        }
    
        fclose(f);
        
        printf("Generated %s\n", output_path);
    }

    printf("Generation complete.\n");
    return 0;
}