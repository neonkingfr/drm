/*
 * Copyright (C) 2008 Maarten Maathuis.
 * All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial
 * portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE COPYRIGHT OWNER(S) AND/OR ITS SUPPLIERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef __NV50_CURSOR_H__
#define __NV50_CURSOR_H__

struct nv50_cursor {
	struct drm_gem_object *gem;
	int x, y;
	bool visible;

	int (*show) (struct nouveau_crtc *crtc, bool update);
	int (*hide) (struct nouveau_crtc *crtc, bool update);
	int (*set_pos) (struct nouveau_crtc *crtc, int x, int y);
	int (*set_offset) (struct nouveau_crtc *crtc);
	int (*set_bo) (struct nouveau_crtc *crtc, struct drm_gem_object *gem);
};

int nv50_cursor_create(struct nouveau_crtc *crtc);
int nv50_cursor_destroy(struct nouveau_crtc *crtc);

#endif /* __NV50_CURSOR_H__ */