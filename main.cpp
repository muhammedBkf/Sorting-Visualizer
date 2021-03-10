#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>



void displayArray(std::vector<int> &,int);
void displayArrayEnd(std::vector<int> &,int);
void generateArray(std::vector<int> &);
void selectionSort(std::vector<int> &);
void insertionSort(std::vector<int> &);

//I set the window as a global variable
sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "SORT visualisation");

#define elementNumber 500

int main()
{

//Initialisation of the array
    std::vector <int> vect(elementNumber);
    generateArray(vect);

//Main loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    //The call for the sorting algorithm with the display function inside
        insertionSort(vect);


    //The final display with the array sorted
        for (int i = 0; i < vect.size(); i++)
        displayArrayEnd(vect,i);
        window.close();

    }

    return 0;
}
void displayArray(std::vector<int> &vect,int index)
{
    float ratio=(float(window.getSize().x/float(elementNumber)));
    window.clear(sf::Color::Black);
    for(int i=0; i<vect.size(); i++)
    {
        sf::RectangleShape  bar(sf::Vector2f(ratio,vect[i]));
        if(i==index+1)
            bar.setFillColor(sf::Color::Red);
        else
            bar.setFillColor(sf::Color::White);
        bar.setPosition(ratio*i,window.getSize().y-vect[i]);
        window.draw(bar);
    }
    sf::sleep(sf::milliseconds(2));

    window.display();
}

void displayArrayEnd(std::vector<int> &vect,int index)
{
    float ratio=(float(window.getSize().x/float(elementNumber)));
    window.clear(sf::Color::Black);
    for(int i=0; i<vect.size(); i++)
    {
        sf::RectangleShape  bar(sf::Vector2f(ratio,vect[i]));
        if(i==index+1)
            bar.setFillColor(sf::Color::Red);
        else if (i <index+1)
            bar.setFillColor(sf::Color::Green);
        else
            bar.setFillColor(sf::Color::White);

        bar.setPosition(ratio*i,window.getSize().y-vect[i]);
        window.draw(bar);
    }
    sf::sleep(sf::milliseconds(10));

    window.display();
}

void generateArray(std::vector<int> &vect)
{
//We will generate elements in the array in the order
// -50 is for that the longest element in the array does not hit the up limit of the window
    for(int i=1; i<elementNumber+1; i++)
        vect[i]=i*((window.getSize().y-50)/float(elementNumber));

//we make 100 random swap
    int i,j;
    srand(time(NULL));
    for(int p=0; p<elementNumber; p++)
    {
        i=rand()%elementNumber;
        j=rand()%elementNumber;
        std::swap(vect[i],vect[j]);
    }
}
void selectionSort(std::vector<int> &vect)
{
    for (int i = 0; i < vect.size()-1; i++)
    {
        for (int j = 0; j < vect.size()-i-1; j++)
        {
            if (vect[j] > vect[j+1])
            {
                std::swap(vect[j], vect[j+1]);
            }
            displayArray(vect,j);
        }
    }
}


void insertionSort(std::vector<int> &vect)
{
    for (int i = 1; i < vect.size() ; i++)
    {
        int key = vect[i];
        int j = i - 1;
        while (vect[j] > key && j >= 0)
        {
            vect[j + 1] = vect[j];
            j--;
            displayArray(vect,j);
        }
        vect[j + 1] = key;
    }
    }
