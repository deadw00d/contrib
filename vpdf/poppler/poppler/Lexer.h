//========================================================================
//
// Lexer.h
//
// Copyright 1996-2003 Glyph & Cog, LLC
//
//========================================================================

//========================================================================
//
// Modified under the Poppler project - http://poppler.freedesktop.org
//
// All changes made under the Poppler project to this file are licensed
// under GPL version 2 or later
//
// Copyright (C) 2006, 2007, 2010 Albert Astals Cid <aacid@kde.org>
// Copyright (C) 2006 Krzysztof Kowalczyk <kkowalczyk@gmail.com>
// Copyright (C) 2013 Adrian Johnson <ajohnson@redneon.com>
// Copyright (C) 2013 Thomas Freitag <Thomas.Freitag@alfa.de>
//
// To see a description of the changes please see the Changelog file that
// came with your tarball or type make ChangeLog if you are building from git
//
//========================================================================

#ifndef LEXER_H
#define LEXER_H

#ifdef USE_GCC_PRAGMAS
#pragma interface
#endif

#include "Object.h"
#include "Stream.h"

class XRef;

#define tokBufSize 128		// size of token buffer

//------------------------------------------------------------------------
// Lexer
//------------------------------------------------------------------------

class Lexer {
public:

  // Construct a lexer for a single stream.  Deletes the stream when
  // lexer is deleted.
  Lexer(XRef *xrefA, Stream *str);

  // Construct a lexer for a stream or array of streams (assumes obj
  // is either a stream or array of streams).
  Lexer(XRef *xrefA, PObject *obj);

  // Destructor.
  ~Lexer();

  // Get the next object from the input stream.
  PObject *getObj(PObject *obj, int objNum = -1);
  PObject *getObj(PObject *obj, const char *cmdA);

  // Skip to the beginning of the next line in the input stream.
  void skipToNextLine();

  // Skip over one character.
  void skipChar() { getChar(); }

  // Get stream.
  Stream *getStream()
    { return curStr.isStream() ? curStr.getStream() : (Stream *)NULL; }

  // Get current position in file.  This is only used for error
  // messages.
  Goffset getPos()
    { return curStr.isStream() ? curStr.streamGetPos() : -1; }

  // Set position in file.
  void setPos(Goffset pos, int dir = 0)
    { if (curStr.isStream()) curStr.streamSetPos(pos, dir); }

  // Returns true if <c> is a whitespace character.
  static GBool isSpace(int c);


  // often (e.g. ~30% on PDF Refernce 1.6 pdf file from Adobe site) getChar
  // is called right after lookChar. In order to avoid expensive re-doing
  // getChar() of underlying stream, we cache the last value found by
  // lookChar() in lookCharLastValueCached. A special value 
  // LOOK_VALUE_NOT_CACHED that should never be part of stream indicates
  // that no value was cached
  static const int LOOK_VALUE_NOT_CACHED = -3;
  int lookCharLastValueCached;

private:

  int getChar(GBool comesFromLook = gFalse);
  int lookChar();

  Array *streams;		// array of input streams
  int strPtr;			// index of current stream
  PObject curStr;		// current stream
  GBool freeArray;		// should lexer free the streams array?
  char tokBuf[tokBufSize];	// temporary token buffer

  XRef *xref;
};

#endif
