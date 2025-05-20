#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>

#define UP    65
#define DOWN  66
#define ENTER 10

void disable_buffering() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

void enable_buffering() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

int get_arrow_key() {
    int c = getchar();
    if (c == 27) {
        if (getchar() == 91) {
            return getchar();
        }
    }
    return c;
}

void get_terminal_size(int *rows, int *cols) {
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    *rows = w.ws_row;
    *cols = w.ws_col;
}

void move_cursor_to(int row, int col) {
    printf("\033[%d;%dH", row, col);
}

void draw_menu(char *options[], int selected, int n) {
    int rows, cols;
    get_terminal_size(&rows, &cols);

    system("clear");

    int menu_height = n;
    int start_row = (rows - menu_height) / 2;

    for (int i = 0; i < n; i++) {
        int len = strlen(options[i]) + 4; // " > " + " <"
        int col = (cols - len) / 2;
        move_cursor_to(start_row + i, col);

        if (i == selected) {
            printf(" > %s <\n", options[i]);
        } else {
            printf("   %s\n", options[i]);
        }
    }
}

int main() {
    char *menu[] = {
        "Iniciar Jogo",
        "Opções",
        "Sair"
    };
    int n = sizeof(menu) / sizeof(menu[0]);
    int selected = 0;
    int key;

    disable_buffering();

    while (1) {
        draw_menu(menu, selected, n);
        key = get_arrow_key();

        if (key == UP) {
            selected = (selected - 1 + n) % n;
        } else if (key == DOWN) {
            selected = (selected + 1) % n;
        } else if (key == ENTER) {
            break;
        }
    }

    enable_buffering();
    system("clear");
    printf("Você selecionou: %s\n", menu[selected]);

    return 0;
}
