#include <vector>
#include <iostream>
#include <ctime>

class Game
{
    public:
        Game (int size_x, int size_y);

        void spawn ();

        void up ();
        void down ();
        void left ();
        void right ();

        void render ();

        void dump ();

        std::vector <std::vector <int>>& data ();
        int& score ();

    private:
        std::vector <std::vector <int>> data_;

        int score_;
};

Game::Game (int size_x, int size_y):
    data_ (size_x, std::vector <int> (size_y)),
    score_ (0)
{
    srand (time (NULL));
}

void Game::spawn ()
{
    int x = rand () % data_.size ();
    int y = rand () % data_[0].size ();

    int value = 2 * ((rand () % 2) + 1);

    if (data_[x][y] == 0)
        data_[x][y] = value;
}

void Game::up ()
{
}

void Game::down ()
{
    for (int j = 0; j < data_[0].size (); j++)
    {
        for (int i = (int) data_.size () - 2; i >= 0; i--)
        {
            if ((data_[i + 1][j] == data_[i][j]) || (data_[i + 1][j] == 0))
            {
                data_[i + 1][j] += data_[i][j];

                data_[i][j] = 0;
            }
        }
    }
}

void Game::left ()
{
}

void Game::right ()
{
}

void Game::render ()
{
}

void Game::dump ()
{
    for (int i = 0; i < data_.size (); i++)
    {
        for (int j = 0; j < data_[i].size (); j++)
            std::cout << data_[i][j] << ' ';

        std::cout << '\n';
    }

    std::cout << '\n';
}

std::vector <std::vector <int>>& Game::data ()
{
    return data_;
}

int& Game::score ()
{
    return score_;
}

int main ()
{
    Game data (4, 4);

    for (int i = 0; i < 10; i++)
        data.spawn ();

    data.dump ();

    data.down ();

    data.dump ();

    return 0;
}
