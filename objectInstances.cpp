// File used to handle instances of room, enemy, and ally objects.

#include "objectInstances.h"

// Player Class Instances


// --------------------------------------------------Room Class Instances--------------------------------------------------
Rooms room1(
    "Entrance", 
    "R001", 
    "A dark and eerie entrance to the dungeon. The air is thick with the smell of damp stone and decay."
);
Rooms room2(
    "Dining Hall", 
    "R002", 
    "A large, grand dining hall with a long table at the center. The walls are adorned with faded tapestries, and the air is filled with the scent of decay and rot."
);
Rooms room3(
    "Armory", 
    "R003", 
    "A small, cramped armory filled with rusted weapons and armor. The air is thick with the smell of metal and dust."
);
Rooms room4(
    "Treasury", 
    "R004", 
    "A luxurious treasury filled with gold and precious gems. The air is thick with the scent of wealth and opulence."
);
Rooms room5(
    "Escape Route", 
    "R005", 
    "A hidden passage that leads to freedom. The air is fresh and clean, a stark contrast to the rest of the dungeon."
);


// --------------------------------------------------Enemy Class Instances--------------------------------------------------
// Enemy Object classes are partially AI Generated. because i'm lazy. and yes i used ai.
Enemies enemy1(
    50, 
    "Goblin", 
    "A small, green creature with sharp teeth and a mischievous grin.", 
    "stinky boi. he attack if u entwer." //"You hear a snarl and then a kackle. Distincively goblin. Are you sure you want to enter?"
);
Enemies enemy2(
    50, 
    "Ghoul", 
    "A thin, yet muscular creature with gray skin and a fierce demeanor.", 
    "A large roar from a ghoul is heard before you enter the room. Are you sure you want to enter?"
);
Enemies enemy3(
    50, 
    "Troll", 
    "A massive, hulking creature with rough, green skin and a brutish nature.", 
    "You spot the troll mucking about before you enter the room. Are you sure you want to enter?"
);
Enemies enemy4(
    50, 
    "Skeleton", 
    "A bony, undead creature with glowing red eyes and a menacing presence.",
    "Hollow bone hits against hollow bone. You hear the noise of a skeleton before you enter the room. Are you sure you want to enter?"
);  
Enemies enemy5(
    50, 
    "Slime", 
    "A gelatinous, amorphous creature that oozes and drips with a sickly blue hue.",
    "A slime is in the room. It hasn't noticed you yet, but you will have to fight it. Are you sure you want to enter?"
);


// --------------------------------------------------Ally Class Instances--------------------------------------------------
