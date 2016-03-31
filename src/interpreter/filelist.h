
/* filelist.h
 *
 * This file is part of fizmo.
 *
 * Copyright (c) 2009-2016 Christoph Ender.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#ifndef filelist_h_INCLUDED
#define filelist_h_INCLUDED

#include "../tools/types.h"

struct z_story_list
{
  struct z_story_list_entry **entries;
  int nof_entries_allocated;
  int nof_entries;
};

struct z_story_list_entry
{
  uint16_t release_number;
  char *serial;
  int length;
  uint16_t checksum;
  uint8_t z_code_version;
  char *title;
  char *author;
  char *language;
  char *description;
  char *filename;
  char *blorbfile;
  char *filetype;
  long storyfile_timestamp;
};

void free_z_story_list(struct z_story_list *story_list);
void free_z_story_list_entry(struct z_story_list_entry *entry);
struct z_story_list *get_z_story_list();
struct z_story_list_entry *get_z_story_entry_from_list(char *serial,
    uint16_t release, uint16_t checksum);
struct z_story_list *update_fizmo_story_list();
void detect_and_add_single_z_file(char *input_filename, char *blorb_filename);
void search_directory(char *absolute_dirname, bool recursive);

#endif /* filelist_h_INCLUDED */

