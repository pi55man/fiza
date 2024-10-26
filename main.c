#include <unistd.h>
#include <raylib.h>
#include <stdio.h>

typedef struct buf{
        char buffer[512];
        int len;
} text;

int spacing = 10;
int main(){
        SetTraceLogLevel(LOG_ERROR);
        InitWindow(800,600,"fiza");
        int cY = 100;
        text txt;
        txt.len = 0;
        txt.buffer[txt.len+1] = '\0';
        
        int tWidth = MeasureText(txt.buffer, 25) + 100;
        SetMouseCursor(MOUSE_CURSOR_IBEAM);
        
        //render loop
        while(!WindowShouldClose()){
                SetTargetFPS(60);

                int key = GetCharPressed();
                if(key >= 32 && key<=125){
                        txt.buffer[txt.len] = (char)key;
                        txt.buffer[txt.len+1] = '\0';
                        txt.len+=1;

                        printf("BUFFER: %s\n",txt.buffer);
                        printf("KEY PRESSED: %c\n",txt.buffer[txt.len-1]);
                } else if(IsKeyPressed(KEY_BACKSPACE)) {
                        txt.len-=1;
                        txt.buffer[txt.len]='\0';
                }

                ClearBackground(BLACK);
                
                BeginDrawing();
                
                int tWidth = MeasureText(txt.buffer, 25)+100;
                if((int)GetTime()%2==0)
                        DrawRectangleLines(tWidth, cY, 2, 20, GRAY);
                
                DrawText(txt.buffer, 100, 100, 25, GRAY);
                printf("twidth = %d\n",tWidth);
                EndDrawing();
        }

        CloseWindow();
        return 0;
}
