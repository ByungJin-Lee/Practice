#pragma once

char blocks[7][2][4] = {
    {
        {0, 0, 0, 0},
        {254,254,254,254}
    },
    {
        {0, 254, 254, 0},
        {0,254,254,0}
    },
    {
        {254, 254, 0, 0},
        {0,254,254,0}
    },
    {
        {0, 0, 254, 0},
        {254,254,254, 0}
    },
    {
        {0, 254, 254, 0},
        {254,254,0,0}
    },
    {
        {0, 254, 0, 0},
        {254,254,254,0}
    },
    {
        {254, 0, 0, 0},
        {254,254,254,0}
    }
};

void start(void);