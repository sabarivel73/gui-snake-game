#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include<stdlib.h>
using namespace std;
using namespace sf;
#define w 35
#define h 20
#define swh 15
#define swh1 13
#define sw w*swh
#define sh h*swh
#define d_k 80
#define u_k 72
#define l_k 75
#define r_k 77
class pro2;
class pro1
{
	private:
		COORD p;
		int l;
		char d;
		vector<COORD> b;
	public:
		pro1(COORD q)
		{
			p = q;
			l = 1;
			b.push_back(p);
		}
		COORD fun1()
		{
			return p;
		}
		void fun2(char a)
		{
			d = a;
		}
		void fun3()
		{
			switch(d)
			{
				case 'u':
					{
						p.Y--;
						break;
					}
				case 'd':
					{
						p.Y++;
						break;
					}
				case 'l':
					{
						p.X--;
						break;
					}
				case 'r':
				{
					p.X++;
					break;
				}
			}
			b.push_back(p);
			if(b.size()>l)
			{
				b.erase(b.begin());
			}
		}
		bool fun4()
		{
			if(p.X==w+1 || p.X==0 || p.Y==h+1 || p.Y==0)
			{
				return true;
			}
			return false;
		}
		bool fun5(pro2 s2);
		void fun6()
		{
			l++;
		}
		vector<COORD> fun7()
		{
			return b;
		}
		bool fun8()
		{
			for(int i=0;i<b.size()-1;i++)
			{
				if(p.X==b[i].X && p.Y==b[i].Y)
				{
					return true;
				}
			}
			return false;
		}
};
class pro2
{
	private:
		COORD p1;
	public:
		pro2()
		{
			srand(time(NULL)); //srand is inbuild function used to get random value based on current time or we give constents to get random value
			fun1();
		}
		void fun1()
		{
			p1.X = rand() % w + 1;
			p1.Y = rand() % h + 1;
		}
		COORD fun2()
		{
			return p1;
		}
};
bool pro1::fun5(pro2 s2)
{
	if(p.X == s2.fun2().X && p.Y == s2.fun2().Y)
	{
		return true;
	}
	return false;
}
pro1 s1({w/2,h/2});
pro2 s2;
int main()
{
	int fr = 0;
	Clock c;
	float t;
	float d = 0.2;
	RenderWindow s(VideoMode(sw,sh),"Game");
    Texture t1,t2;
    t1.loadFromFile("images/1.png");
    t2.loadFromFile("images/2.png");
    Sprite sp1(t1);
    Sprite sp2(t2);
    while(s.isOpen())
    {
        float t1 = c.getElapsedTime().asSeconds();
        t = t+t1;
        c.restart();
        Event e;
        while(s.pollEvent(e))
        {
            if(e.type==Event::Closed)
            {
                s.close();
            }
        }
        if(Keyboard::isKeyPressed(Keyboard::Left))
        {
            s1.fun2('l');
        }
        if(Keyboard::isKeyPressed(Keyboard::Right))
        {
            s1.fun2('r');
        }
        if(Keyboard::isKeyPressed(Keyboard::Down))
        {
            s1.fun2('d');
        }
        if(Keyboard::isKeyPressed(Keyboard::Up))
        {
            s1.fun2('u');
        }
        if(t>d)
        {
            s1.fun3();
            t = 0;
            if(s1.fun5(s2))
            {
                s1.fun6();
                fr++;
                s2.fun1();
            }
        }
        s.clear();
        sp1.setPosition(0,0);
        s.draw(sp1);
        vector<COORD>sps = s1.fun7();
        int k = 0;
        while(k<sps.size())
        {
            sp2.setPosition(sps[k].X*swh1,sps[k].Y*swh1);
            s.draw(sp2);
            k++;
        }
        sp2.setPosition(s2.fun2().X*swh1,s2.fun2().Y*swh1);
        s.draw(sp2);
        if(s1.fun4()||s1.fun8())
        {
            s.clear();
            Text t2;
            Text t3;
            stringstream frs;
            string frs1 = "Score : ";
            frs<<frs1;
            frs<<fr;
            t3.setString(frs.str().c_str());
            t2.setString("Game Over");
            Font f;
            if(!f.loadFromFile("font/fb.otf"))
            {
                cout<<"Font not load"<<endl;
            }
            t2.setFont(f);
            t3.setFont(f);
            t2.setFillColor(Color::Red);
            t3.setFillColor(Color::Red);
            t2.setCharacterSize(50);
            t3.setCharacterSize(35);
            t2.setStyle(Text::Bold);
            t3.setStyle(Text::Bold);
            t2.setPosition(sw/5,sh/5);
            t3.setPosition(0,0);
            sp1.setPosition(0,0);
            s.draw(sp1);
            s.draw(t2);
            s.draw(t3);
            s.display();
            Sleep(3000);
            break;
        }
        s.display();
    }
	return 0;
}
