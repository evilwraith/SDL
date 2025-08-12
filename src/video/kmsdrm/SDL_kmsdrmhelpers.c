#include "SDL_internal.h"            /* inside SDL it’s fine to use internals */
#include "SDL_kmsdrmvideo.h"         /* SDL’s KMSDRM internals */
#include "SDL3/SDL_kmsdrm_helpers.h" /* the public declaration you added */

SDL_DECLSPEC int SDLCALL
SDL_KMSDRM_GetGBMHandles(SDL_Window *window,
                         struct gbm_device **out_dev,
                         struct gbm_surface **out_surf)
{
    if (!window || !out_dev || !out_surf) {
        return -1;
    }

    SDL_WindowData *windata = window->internal;
    if (!windata) {
        return -1;
    }
    SDL_VideoData *viddata = windata->viddata;
    if (!viddata) {
        return -1;
    }

    /* Optional: treat “mock GBM” sentinel as error */
    if ((void*)viddata->gbm_dev == (void*)0x1 || (void*)windata->gs == (void*)0x1) {
        *out_dev = NULL;
        *out_surf = NULL;
        SDL_LogWarn(SDL_LOG_CATEGORY_VIDEO,
                    "KMSDRM: mock GBM sentinel detected; refusing to hand out GBM handles.");
        return -1;
    }

    if (!viddata->gbm_dev || !windata->gs) {
        *out_dev = NULL;
        *out_surf = NULL;
        return -1;
    }

    *out_dev  = (struct gbm_device *)viddata->gbm_dev;
    *out_surf = (struct gbm_surface *)windata->gs;
    return 0;
}
