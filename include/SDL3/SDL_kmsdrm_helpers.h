/* Simple, public helper to fetch GBM handles for a KMSDRM-backed SDL_Window. */
#ifndef SDL_KMSDRM_HELPERS_H_
#define SDL_KMSDRM_HELPERS_H_

#include <SDL3/SDL_stdinc.h>
#include <SDL3/SDL_video.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations keep this header independent of <gbm.h>. */
struct gbm_device;
struct gbm_surface;

/* Returns 0 on success, non-zero on failure. On success both out pointers are non-NULL. */
SDL_DECLSPEC int SDLCALL SDL_KMSDRM_GetGBMHandles(SDL_Window *window,
                                                  struct gbm_device **out_dev,
                                                  struct gbm_surface **out_surf);

#ifdef __cplusplus
} /* extern "C" */
#endif
#endif /* SDL_KMSDRM_HELPERS_H_ */
