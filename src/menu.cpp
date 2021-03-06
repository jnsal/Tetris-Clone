#include "menu.hpp"
#include "renderWindow.hpp"
#include "text.hpp"

void func_test(int a)
{
    abort();
}

void Menu(RenderWindow &window)
{
    sf::Clock c;
    sf::Sprite background;
    sf::Texture bg;
    bg.loadFromFile("../textures/default-background.png");
    background.setTexture(bg);

	Button start(V2(232.f, 133.f), sf::IntRect(0.f, 26.f, 32.f, 16.f), 4, 0.2f, sf::IntRect(0.f, 222.f, 9.f, 9.f), "Start");
    start.setScale(3.f);
    Button options(V2(232.f, 216.f), sf::IntRect(0.f, 26.f, 32.f, 16.f), 4, 0.2f, sf::IntRect(0.f, 231.f, 9.f, 9.f), "Options");
    options.setScale(3.f);
	Image logo(V2(214.f, 15.f), sf::IntRect(0.f, 0.f, 40.f, 23.f), 8, 0.2f);
    logo.setScale(3.2f);
    options.setOnReleasedFunction([&window]() { Options(window); } );
    start.setOnReleasedFunction([&window]() { Tetris(window); } );

    window.playOST();    
    Keyboard k;
	while(window.isOpen())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::T)) {
			window.clear();
            Tetris(window);
            c.restart();
		}
        // NOTE: When go to the game em press Escape, is getting out of the game directly.	
        // tried to make a static function but still don't work
        sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
                window.Quit();
			}
		}
		
		if (Keyboard::justPressedGlobal(sf::Keyboard::Key::Escape) && c.getElapsedTime().asSeconds() >= 0.2f) {
            window.Quit();
		}
		// ----------------------
		window.draw(background);
		logo.Update(&window);
		
		start.Update(&window);
        options.Update(&window);
        // ----------------------
		/*
		// Preserve Aspect ratio
		if (window.getSize().x != window_size.x || window.getSize().y != window_size.y) 
		{
			view.setSize((float)window.getSize().x, (float)window.getSize().y);
			if ((double)window.getSize().x / window.getSize().y == aspect_ratio)  {
				view = window.getDefaultView(); // don't that, need to pick up last aspect useful
				std::cout << window.getSize().x << " : " << window.getSize().y << std::endl;
			}
			window.setView(view);
			window_size = sf::Vector2f(window.getSize());
		*/
	    window.Update();	
	}
}
