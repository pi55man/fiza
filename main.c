#include <unistd.h>
#include <raylib.h>
#include <stdio.h>

typedef struct buf{
        char buffer[512];
        int len;
        
} text;

int spacing = 25;
int main(){

        InitWindow(800,600,"fiza");
        int cX = 100;
        int cY = 100;
        text txt;
        txt.len = 0;
        txt.buffer[txt.len+1] = '\0';
        
        //render loop
        while(!WindowShouldClose()){
                SetTargetFPS(60);

                int key = GetCharPressed();
                if(key >= 32 && key<=125){
                        txt.buffer[txt.len] = (char)key;
                        txt.buffer[txt.len+1] = '\0';
                        txt.len+=1;
                        cX+=spacing;
                        printf("DEBUG: %s",txt.buffer);
                }

                if(key==KEY_BACKSPACE){
                        txt.len-=1;
                        txt.buffer[txt.len]=' ';
                }

                ClearBackground(BLACK);
                BeginDrawing();
                
                if((int)GetTime()%2==0)
                        DrawRectangleLines(cX, cY, 2, 20, GRAY);
                
                DrawText(txt.buffer, 100, 100, 25, GRAY);
                EndDrawing();
        }

        CloseWindow();
        return 0;
}
