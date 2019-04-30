/*
** EPITECH PROJECT, 2018
** my_hunter
** File description:
** Init
*/

#include "minigame.h"

int init_engine(t_minigame *game)
{
    game->engine.video_mode.width = 800;
    game->engine.video_mode.height = 600;
    game->engine.video_mode.bitsPerPixel = 32;
    game->engine.window =
        sfRenderWindow_create(game->engine.video_mode, "Fight the bugs !",
        sfDefaultStyle, NULL);
    game->engine.background.texture =
        sfTexture_createFromFile("res/wallpaper.jpg", NULL);
    game->engine.background.sprite = sfSprite_create();
    if (game->engine.window == 0 ||
        game->engine.background.texture == 0 ||
        game->engine.background.sprite == 0)
        return (-1);
    sfSprite_setTexture(game->engine.background.sprite,
                        game->engine.background.texture, sfTrue);
    return (0);
}

int init_score(t_minigame *game)
{
    game->score.score_pos.x = 600;
    game->score.score_pos.y = 500;
    game->score.nb_score = 0;
    game->score.color.r = 255;
    game->score.color.g = 255;
    game->score.color.b = 255;
    game->score.color.a = 255;
    game->score.font = sfFont_createFromFile("res/arial.ttf");
    if (game->score.font == 0)
        return (-1);
    game->score.text = sfText_create();
    sfText_setString(game->score.text, int_to_text(game->score.nb_score));
    sfText_setFont(game->score.text, game->score.font);
    sfText_setCharacterSize(game->score.text, 50);
    sfText_setPosition(game->score.text, game->score.score_pos);
    sfText_setColor(game->score.text, game->score.color);
    return (0);
}

int init_bugs(t_minigame *game)
{
    game->bug.texture = sfTexture_createFromFile("res/bug.png", NULL);
    if (game->bug.texture == 0) {
        return (-1);
    }
    game->bug.sprite = sfSprite_create();
    if (game->bug.sprite == 0) {
        return (-1);
    }
    sfSprite_setTexture(game->bug.sprite, game->bug.texture, sfTrue);
    game->bug.rect.left = 0;
    game->bug.rect.top = 0;
    game->bug.rect.height = 110;
    game->bug.rect.width = 85;
    game->bug.pos.x = -120;
    game->bug.pos.y = 0;
    game->bug.clock = sfClock_create();

    if (game->bug.clock == 0)
        return (-1);
    return (0);
}

int init_sound(t_minigame *game)
{
    game->sound.soundbuffer = sfSoundBuffer_createFromFile("res/music.ogg");
    if (game->sound.soundbuffer == 0) {
        return (-1);
    }
    game->sound.music = sfSound_create();
    if (game->sound.music == 0) {
        return (-1);
    }
    sfSound_setBuffer(game->sound.music, game->sound.soundbuffer);
    sfSound_play(game->sound.music);
    return (0);
}

int init_game(t_minigame *game)
{
    int (*ptr[5])(t_minigame*);
    int i = 0;

    ptr[0] = init_engine;
    ptr[1] = init_score;
    ptr[2] = init_bugs;
    ptr[3] = init_sound;
    ptr[4] = 0;
    while (ptr[i] != 0) {
        if (ptr[i](game) == -1) {
            return (-1);
        }
        i++;
    }
    return (0);
}
