#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Player {
public:
    int x, y;

    Player(int startX, int startY) : x(startX), y(startY) {}

    void moveLeft() {
        x--;
    }

    void moveRight() {
        x++;
    }
};

class Bullet {
public:
    int x, y;
    bool isActive;

    Bullet() : x(0), y(0), isActive(false) {}

    void activate(int playerX, int playerY) {
        x = playerX;
        y = playerY - 1;
        isActive = true;
    }

    void move() {
        y--;
        if (y < 0) {
            isActive = false;
        }
    }
};

class Target {
public:
    int x, y;
    bool isActive;

    Target() : x(0), y(0), isActive(false) {}

    void activate(int maxX) {
        x = rand() % maxX;
        y = 9;  // Y-coordinate for targets (adjust as needed)
        isActive = true;
    }

    void move() {
        y--;
        if (y < 0) {
            isActive = false;
        }
    }
};

bool isCollision(const Bullet& bullet, const Target& target) {
    return (bullet.x == target.x && bullet.y == target.y && target.isActive);
}

int main() {
    srand(time(0));  // Seed for random number generation

    const int maxX = 10;  // Adjust as needed
    Player player(maxX / 2, 10);  // Initial player position
    Bullet bullet;
    Target target;

    char input;

    while (true) {
        // Update player position based on user input
        cout << "Press 'A' to move left, 'D' to move right, or 'Q' to quit: ";
        cin >> input;

        switch (input) {
            case 'A':
            case 'a':
                player.moveLeft();
                break;
            case 'D':
            case 'd':
                player.moveRight();
                break;
            case 'Q':
            case 'q':
                cout << "Game Over\n";
                return 0;
            default:
                break;
        }

        // Activate a bullet when the user presses the spacebar
        if (input == ' ') {
            if (!bullet.isActive) {
                bullet.activate(player.x, player.y);
            }
        }

        // Move the bullet and target
        if (bullet.isActive) {
            bullet.move();
        }

        if (target.isActive) {
            target.move();
        } else {
            target.activate(maxX);
        }

        // Check for collisions
        if (isCollision(bullet, target)) {
            cout << "Target hit!\n";
            target.isActive = false;
            bullet.isActive = false;
        }

        // Display the game state
        for (int i = 0; i < maxX; i++) {
            if (i == player.x) {
                cout << 'P';  // Player
            } else if (i == bullet.x && bullet.isActive) {
                cout << '|';  // Bullet
            } else if (i == target.x && target.isActive) {
                cout << 'T';  // Target
            } else {
                cout << ' ';
            }
        }
        cout << endl;

        // Add a delay for better visualization
        for (int i = 0; i < 10000000; i++) {}

        // Clear the console screen (for better animation)
        system("clear || cls");
    }

    return 0;
}
