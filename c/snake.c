#include <ncurses.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <signal.h>

#define MAX_SNAKE_LENGTH 1000

typedef struct {
    int y;
    int x;
} Coord;

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;

typedef struct {
    WINDOW *win;
    int height, width;
    int game_height, game_width;
    Coord snake[MAX_SNAKE_LENGTH];
    int snake_length;
    Coord food;
    Direction direction;
    int score;
    bool game_over;
} SnakeGame;

void reset_game(SnakeGame *game) {
    int start_y = game->game_height / 2;
    int start_x = game->game_width / 2;

    game->snake_length = 3;
    game->snake[0] = (Coord){start_y, start_x};
    game->snake[1] = (Coord){start_y, start_x - 1};
    game->snake[2] = (Coord){start_y, start_x - 2};

    game->direction = RIGHT;
    game->score = 0;
    game->game_over = false;

    // Generate food
    while (1) {
        int fy = rand() % (game->game_height - 2) + 1;
        int fx = rand() % (game->game_width - 2) + 1;
        bool collision = false;
        for (int i = 0; i < game->snake_length; i++) {
            if (game->snake[i].y == fy && game->snake[i].x == fx) {
                collision = true;
                break;
            }
        }
        if (!collision) {
            game->food = (Coord){fy, fx};
            break;
        }
    }
}

void draw_border(SnakeGame *g) {
    for (int x = 0; x < g->game_width; x++) {
        mvwaddch(g->win, 0, x, '─');
        mvwaddch(g->win, g->game_height - 1, x, '─');
    }
    for (int y = 0; y < g->game_height; y++) {
        mvwaddch(g->win, y, 0, '│');
        mvwaddch(g->win, y, g->game_width - 1, '│');
    }

    mvwaddch(g->win, 0, 0, '┌');
    mvwaddch(g->win, 0, g->game_width - 1, '┐');
    mvwaddch(g->win, g->game_height - 1, 0, '└');
    mvwaddch(g->win, g->game_height - 1, g->game_width - 1, '┘');
}

void draw_snake(SnakeGame *g) {
    for (int i = 0; i < g->snake_length; i++) {
        char ch = (i == 0) ? 'O' : 'o';
        wattron(g->win, COLOR_PAIR(1));
        mvwaddch(g->win, g->snake[i].y, g->snake[i].x, ch);
        wattroff(g->win, COLOR_PAIR(1));
    }
}

void draw_food(SnakeGame *g) {
    wattron(g->win, COLOR_PAIR(2));
    mvwaddch(g->win, g->food.y, g->food.x, '*');
    wattroff(g->win, COLOR_PAIR(2));
}

void draw_score(SnakeGame *g) {
    wattron(g->win, COLOR_PAIR(3));
    mvwprintw(g->win, g->game_height, 2, "Score: %d", g->score);
    wattroff(g->win, COLOR_PAIR(3));
    mvwprintw(g->win, g->game_height + 1, 2, "Arrow keys: Move | Q: Quit");
}

void draw_game_over(SnakeGame *g) {
    const char *msg1 = "GAME OVER!";
    const char *msg2 = "Press R to restart or Q to quit";

    int y = g->game_height / 2;
    int x1 = (g->game_width - strlen(msg1)) / 2;
    int x2 = (g->game_width - strlen(msg2)) / 2;

    wattron(g->win, COLOR_PAIR(4) | A_BOLD);
    mvwprintw(g->win, y, x1, msg1);
    wattroff(g->win, COLOR_PAIR(4) | A_BOLD);
    mvwprintw(g->win, y + 2, x2, msg2);
}
