#include<isurface.hpp>


ISurface::ISurface(SDL_Surface* surf) {
  m_surf = surf;
  m_rect.x = m_rect.y = 0;         // OMG mrekk osu
  m_rect.w = surf->w; m_rect.h = surf->h;
}

ISurface::ISurface(const char* path) {
  m_surf = SDL_LoadBMP(path);
  m_rect.x = m_rect.y = 0;
  m_rect.w = m_surf->w; m_rect.h = m_surf->h;
}

ISurface::~ISurface() {
  SDL_FreeSurface(m_surf);
}

void ISurface::SDLBlit(SDL_Surface* src, int x, int y) {
  SDL_Rect rect;
  rect.x = x; rect.y = y;
  rect.w = src->w; rect.h = src->h;
  SDL_UpperBlit(src, NULL, m_surf, &rect);
}

void ISurface::SDLBlitTo(SDL_Surface* dest, int x, int y) {
  SDL_Rect rect = m_rect;
  rect.x = x; rect.y = y;
  SDL_UpperBlit(m_surf, NULL, dest, &rect);
}

void ISurface::Blit(ISurface src, int x, int y) {
  SDL_Rect rect = src.m_rect;
  rect.x = x; rect.y = y;
  SDL_UpperBlit(src.m_surf, NULL, m_surf, &rect);
}

void ISurface::_UpperBlit(SDL_Surface* dest, SDL_Rect* src_rect, SDL_Rect* dest_rect) {
  SDL_UpperBlit(m_surf, src_rect, dest, dest_rect);
}