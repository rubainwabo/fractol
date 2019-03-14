#include "fractol.h"
//WANTED
void    init_thread(t_fract *fract, t_thread data[8])
{
    data[0] = (t_thread){.x_start = 0, .y_start = 0, .y_end = HEIGHT / 2,
        .x_end = WIDTH / 4, .f = fract};
    data[1] = (t_thread){.x_start = WIDTH / 4, .y_start = 0,
        .y_end = HEIGHT / 2, .x_end = WIDTH / 2, .f = fract};
    data[2] = (t_thread){.x_start = WIDTH / 2, .y_start = 0,
        .y_end = HEIGHT / 2, .x_end = (WIDTH * 3) / 4, .f = fract};
    data[3] = (t_thread){.x_start = (WIDTH * 3) / 4, .y_start = 0,
        .y_end = HEIGHT / 2, .x_end = WIDTH, .f = fract};
    data[4] = (t_thread){.x_start = 0, .y_start = HEIGHT / 2,
       .y_end = HEIGHT, .x_end = WIDTH / 4, .f = fract};
    data[5] = (t_thread){.x_start = WIDTH / 4, .y_start = HEIGHT / 2,
        .y_end = HEIGHT, .x_end = WIDTH / 2, .f = fract};
    data[6] = (t_thread){.x_start = WIDTH / 2, .y_start = HEIGHT / 2,
        .y_end = HEIGHT, .x_end = (WIDTH * 3) / 4, .f = fract};
    data[7] = (t_thread){.x_start = (WIDTH * 3) / 4, .y_start = HEIGHT / 2,
        .y_end = HEIGHT, .x_end = WIDTH, .f = fract};
}

void     launch_threads(t_fract *fract)
{
    pthread_t ids[8];
    t_thread data[8];
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    init_thread(fract, data);
    pthread_create(&(ids[0]), &attr, fract->thread, &data[0]);
    pthread_join(ids[0], NULL);
    pthread_create(&(ids[1]), &attr, fract->thread, &data[1]);
    pthread_join(ids[1], NULL);
    pthread_create(&(ids[2]), &attr, fract->thread, &data[2]);
    pthread_join(ids[2], NULL);
    pthread_create(&(ids[3]), &attr, fract->thread, &data[3]);
    pthread_join(ids[3], NULL);
    pthread_create(&(ids[4]), &attr, fract->thread, &data[4]);
    pthread_join(ids[4], NULL);
    pthread_create(&(ids[5]), &attr, fract->thread, &data[5]);
    pthread_join(ids[5], NULL);
    pthread_create(&(ids[6]), &attr, fract->thread, &data[6]);
    pthread_join(ids[6], NULL);
    pthread_create(&(ids[7]), &attr, fract->thread, &data[7]); 
    pthread_join(ids[7], NULL);
}