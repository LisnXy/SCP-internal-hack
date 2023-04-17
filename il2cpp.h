#pragma once

#include <Windows.h>
#include <cstdint>

struct PlayerList_o {
	PlayerList_c* klass;
	void* monitor;
};

struct PlayerList_c {
	BYTE _1[176];
	struct PlayerList_StaticFields* static_fields;
};

struct PlayerList_StaticFields {
	LPVOID _refreshRate;
	LPVOID Title;
	bool _eventsAssigned;
	LPVOID _alreadyAddedPlayers;
	LPVOID ica;
	struct PlayerList_o* singleton;
	LPVOID s_parent;
	LPVOID s_template;
	bool _anyAdminOnServer;
	struct System_Collections_Generic_List_PlayerList_Instance__o* instances;
};

struct System_Collections_Generic_List_PlayerList_Instance__o {
	System_Collections_Generic_List_PlayerList_Instance__c* klass;
	void* monitor;
	System_Collections_Generic_List_PlayerList_Instance__Fields fields;
};