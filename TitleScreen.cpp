#include"TitleScreen.h"

InputManager titleInput;

TitleScreen::TitleScreen(void)
{
}

TitleScreen::~TitleScreen(void)
{
}

void TitleScreen::LoadContent()
{
    font= al_load_font("font1.ttf", 30, NULL);
}

void TitleScreen::UnloadContent()
{
    al_destroy_font(font);
}

void TitleScreen::Update(ALLEGRO_EVENT ev)
{
    if(titleInput.IsKeyPressed(ev, ALLEGRO_KEY_ENTER))
            screenManager::GetInstance(), Addcreen(new SplashScreen);
}

void TitleScreen::Draw(ALLEGRO_DISPLAY *display)
{
    al_draw_text(font, al_map_rgb(255, 0, 0), 100, 100, NULL, "TitleScreen");

}
