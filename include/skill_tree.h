/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** skill_tree
*/

#pragma once

#include <SFML/Graphics.h>

typedef struct ll_simple_s {
    struct ll_simple_s *next;
    void *data;
} ll_simple_t;

typedef struct sk_child_s {
    int parent_id;
    char *child;
} sk_child_t;

typedef struct sk_ginfo_s {
    int animation_id;
    sfVector2f pos;
} sk_ginfo_t;

typedef enum sk_id_e {
    inc_barr_hs,
    inc_barr_h,
    inc_barr_s,
    sk_end_list
} sk_id_t;

typedef struct skill_s {
    sk_ginfo_t info;
    sk_child_t inheritence;
    int status;
    sk_id_t id;
} skill_t;
// coordinates will be set deênding of the center of the image

static const skill_t skill_list[] = {
    {{0, {0, 0}}, {0, "increased health and sanity bar"}, 0, inc_barr_hs},
    {{0, {-100, -100}}, {inc_barr_hs, "increased health bar"}, 0, inc_barr_h},
    {{0, {100, -100}}, {inc_barr_hs, "increased sanity bar"}, 0, inc_barr_s},
    {{0, {0, 0}}, {sk_end_list, NULL}, 0, sk_end_list}
};