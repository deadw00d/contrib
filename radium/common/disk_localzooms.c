/* Copyright 2000 Kjetil S. Matheussen

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA. */






#include "nsmtracker.h"
#include "disk.h"
#include "disk_placement_proc.h"
#include "list_proc.h"
#include "reallines_proc.h"

#include "disk_localzooms_proc.h"


void SaveLocalZooms_Uplevel(struct LocalZooms *localzoom){

	while(localzoom!=NULL){
		DC_start("LOCALZOOM");

			SavePlace(&localzoom->l.p);

			DC_SaveI(localzoom->zoomline);
			DC_SaveI(localzoom->level);

			SaveLocalZooms_Uplevel(localzoom->uplevel);


		DC_end();
		localzoom=NextLocalZoom(localzoom);
	}

}

void SaveLocalZooms(struct LocalZooms *localzoom,int num_lines){
DC_start("LOCALZOOMS");

	DC_SaveI(num_lines);

	while(localzoom!=NULL){

		/* We don't save the localzooms at level 0, because it takes up
		   enourmeously much space (+/- 1/3 of the savefile). The info
         in the localzooms at level zero is allso very easy to reconstruate
		   afterwards. (NB. It does not take up very much space in memory).
		*/

		SaveLocalZooms_Uplevel(localzoom->uplevel);
		localzoom=NextLocalZoom(localzoom);
	}

DC_end();
}



void LoadLocalZooms_Uplevel(struct LocalZooms **to){
	int ret;

	struct LocalZooms *localzoom;


	for(;;){
		ret=DC_Next();
		switch(ret){
			case LS_OBJECT:

				localzoom=DC_alloc(sizeof(struct LocalZooms));
				LoadPlace(&localzoom->l.p);
				localzoom->zoomline=DC_LoadI();
				localzoom->level=DC_LoadI();

				DC_ListAdd3(to,localzoom);

				LoadLocalZooms_Uplevel(&localzoom->uplevel);

				break;

			case LS_ENDOBJECT:
			case LS_ERROR:
				return;
		}
	}


error:
	return;
}


void LoadLocalZooms(struct LocalZooms **to){
	int num_lines=DC_LoadI();
	struct LocalZooms *localzoom;
	struct LocalZooms *uplevel;
	Place place;
	int lokke;
	int ret;

	place.counter=0;
	place.dividor=1;

	for(lokke=0;lokke<num_lines;lokke++){
		localzoom=DC_alloc(sizeof(struct LocalZooms));
		localzoom->Tline=lokke;
		localzoom->Tdividor=1;
		localzoom->zoomline=lokke;
		ListAddElement3(to,&localzoom->l);
	}

	for(;;){
		ret=DC_Next();
		switch(ret){
			case LS_OBJECT:

				localzoom=DC_alloc(sizeof(struct LocalZooms));
				LoadPlace(&localzoom->l.p);
				localzoom->zoomline=DC_LoadI();
				localzoom->level=DC_LoadI();
				place.line=localzoom->Tline;
				uplevel=ListFindElement3(&((*to)->l),&place);
				DC_ListAdd3(&uplevel->uplevel,localzoom);

				LoadLocalZooms_Uplevel(&localzoom->uplevel);
				break;

			case LS_ENDOBJECT:
			case LS_ERROR:
				return;
		}
	}

error:
	return;
}


void DLoadLocalZooms(
	struct Root *newroot,
	struct Tracker_Windows *window,
	struct WBlocks *wblock
){
	UpdateRealLines(window,wblock);
	UpdateReallinesDependens(window,wblock);
}







