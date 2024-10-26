#include <unistd.h>
#include <raylib.h>
#include <stdio.h>
#include <math.h>
#include <malloc.h>

typedef struct buf{
        char buffer[512];
        int len;
} text;




text* buffer_init(){
        text* txt = (text*)malloc(sizeof(text));
        txt->len = 0;
        txt->buffer[txt->len+1] = '\0';
        return txt;
}

int main(){

        SetTraceLogLevel(LOG_ERROR);
        InitWindow(800,600,"fiza");
        int cursorY = 100;
        text* txt = buffer_init();
        
        int cursorX = MeasureText(txt->buffer, 25) + 100;
        SetMouseCursor(MOUSE_CURSOR_IBEAM);
        
        //render loop
        while(!WindowShouldClose()){
                SetTargetFPS(60);

                int key = GetCharPressed();
                if(key >= 32 && key<=125){
                        txt->buffer[txt->len] = (char)key;
                        txt->buffer[txt->len+1] = '\0';
                        txt->len+=1;
                        int cursorX = MeasureText(txt->buffer, 25)+100;

                        printf("BUFFER: %s\n",txt->buffer);
                        printf("KEY PRESSED: %c\n",txt->buffer[txt->len-1]);
                }

                if(IsKeyPressed(KEY_BACKSPACE)) {
                        if(txt->len>0){
                        txt->len-=1;
                        txt->buffer[txt->len]='\0';
                        int cursorX = MeasureText(txt->buffer, 25)+100;
                }}

                if(IsKeyPressed(KEY_ENTER)){
                        txt->buffer[txt->len] = '\n';  
                        txt->len+=1;
                        txt->buffer[txt->len] = '\0';
                        
                        //Vector2 d = MeasureTextEx(GetFontDefault(), txt.buffer, 25, 0);
                        //cursorY+=d.y;
                        //cursorX=100;
                }
                
                if(IsKeyPressed(KEY_RIGHT_CONTROL)){
                        printf("saved! \n");
                        SaveFileText("note.txt", txt->buffer);

                }

                ClearBackground(BLACK);

                //drawing
                BeginDrawing();
                
                int cursorX = MeasureText(txt->buffer, 25)+100;
                //cursor
                if(fmod(GetTime(), 0.5f)<0.25)
                        DrawRectangleLines(cursorX, cursorY, 2, 20, GRAY);
                
                //buffer
                DrawText(txt->buffer, 100, 100, 25, GRAY);
                EndDrawing();
        }

        CloseWindow();
        return 0;
}
