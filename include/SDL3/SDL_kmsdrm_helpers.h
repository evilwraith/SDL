#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_video.h>
struct gbm_device;
struct gbm_surface;

#ifdef __cplusplus
extern "C" {
#endif

SDL_DECLSPEC int SDLCALL
SDL_KMSDRM_GetGBMHandles(SDL_Window *window,
                         struct gbm_device **out_dev,
                         struct gbm_surface **out_surf);

#ifdef __cplusplus
} /* extern "C" */
#endif
