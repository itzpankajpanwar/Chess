#include <SFML/Graphics.hpp>
#include<bits/stdc++.h>
using namespace sf;


int size=56;
int k=0;
//array to store all pieces
Sprite f[32];

int chessBoard[8][8] = 
    {-1,0,-3,-4,-5,-3,-2,-1,
     -6,-6,-6,0,-6,-6,0,-6,
      0, 0, -2, 0, 0, 0, 0, 0,
      0, 0, 0, -6, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0,
      6, 6, 6, 6, 6, 6, 6, 6,
      1, 0, 3, 4, 5, 3, 2, 1
    };

    
void loadposition()
{
   /// int k=0;
    for(int i=0;i<8;i++)
    for(int j=0;j<8;j++)
    {
        int n=chessBoard[i][j];
        if(!n) continue;
        int x=abs(n)-1;
        int y= n>0?1:0;
        f[k].setTextureRect( IntRect(size*x,size*y,size,size));
        f[k].setPosition(size*j,size*i);
        k++;
    }
}
int main()
{   
   
   
    RenderWindow window(VideoMode(504, 504), "PANKAJ CHESS");
    Texture t1,t2;
    t1.loadFromFile("images/figures.png");
    t2.loadFromFile("images/board0.png");
    for(int i=0;i<32;i++) f[i].setTexture(t1);
    Sprite board(t2);
    Sprite s(t1);

    loadposition();

    while(window.isOpen()){
        Event e;
        while(window.pollEvent(e)){
            if(e.type == Event::Closed) window.close();
        }
        window.clear();
        window.draw(board);
        for(int i=0; i<k; ++i) window.draw(f[i]);
        window.display();
    }
    return 0;
}