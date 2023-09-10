#include <stdio.h>
#include <math.h>
#include <time.h>
#include "raylib.h"

#define WIDTH 1920
#define HEIGHT 1080

Vector2 getHandEdge(Vector2 *position, double length, double turns){
  // Got really close to this by myself, but for some reason wasn't working because
  // I was not casting as float, so I got these from
  // https://elm-lang.org/examples/clock
  double t = 2 * PI * (turns - 0.25);
  double outX = position->x + length * cos(t);
  double outY = position->y + length * sin(t);

  return (Vector2) {
    outX,
    outY
  };
}


int main() {
  InitWindow(WIDTH, HEIGHT, "Raylib Test");
  SetTargetFPS(60);

  Vector2 screenCenter = (Vector2){WIDTH / 2, HEIGHT / 2};
  Vector2 hours = (Vector2){WIDTH / 2, 0};
  Vector2 minutes = (Vector2){WIDTH / 2, 0};
  Vector2 seconds = (Vector2){WIDTH / 2, 0};

  time_t now = time(NULL);
  struct tm *currentTime;
  now = time(NULL);
  currentTime = localtime(&now);
  hours = getHandEdge(&screenCenter, 200, (float) (currentTime->tm_hour % 12) / 12);
  minutes = getHandEdge(&screenCenter, 400, (float)currentTime->tm_min / 60);
  seconds = getHandEdge(&screenCenter, 400, (float)currentTime->tm_sec / 60);

  while (!WindowShouldClose())
  {
      BeginDrawing();
        ClearBackground(BLACK);
        DrawLineV(screenCenter, hours, RAYWHITE);
        DrawLineV(screenCenter, minutes, RED);
        DrawLineV(screenCenter, seconds, BLUE);
        now = time(NULL);
        currentTime = localtime(&now);
        hours = getHandEdge(&screenCenter, HEIGHT, (float)(currentTime->tm_hour % 12) / 12);
        minutes = getHandEdge(&screenCenter, HEIGHT, (float)currentTime->tm_min / 60);
        seconds = getHandEdge(&screenCenter, HEIGHT, (float)currentTime->tm_sec / 60);
      EndDrawing();
  }
  CloseWindow();

  return 0;
};
