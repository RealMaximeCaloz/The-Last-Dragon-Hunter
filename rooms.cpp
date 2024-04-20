// rooms.cpp
#include "rooms.h"

// Function to initialize the vector of rooms
std::vector<Room> initializeRooms() {
    std::vector<Room> rooms = {
        // Define your rooms here
        {
            0,
            "Welcome to The Last Dragon Hunter.\nLong ago, dragon hunters roamed the Earth, nearly driving dragon kind to extinction. For humans, there was no longer much fear of having their crops burnt by fire, or their entire population of sheep eaten by an insatiable dragon. However, such peace of mind could not last. It was destined to fail, as the cycle repeats itself without fail. The elders attempted to warn the younger generations, but alas, to no avail. Disregarding the elders’ warnings, dragon hunting was a profession that progressively grew out of style. It could not pay the bills anymore. The last remaining dragon hunters were being made fun of, as there was barely any work left for them to do. What are you training for? Slaying the ghost of a dragon? And so, as they seemingly became useless, dragon hunters became extinct, almost like the very dragons they were meant to exterminate. Without the purview of dragon hunters, the few remaining dragons who had been in hiding became emboldened. More and more sheep were being eaten, fields burnt, houses destroyed. The age of dragons was back. Soon, the dragons successfully repopulated, until their population reached a critical mass that was synonymous to the impending destruction of the world as humans knew it. The peace was gone. Even the King would not be able to sleep well at night, fearing a draconic invasion storming the castle. With no dragon hunters left, all hope seemed lost. Until now.\nYou slowly open your eyes with a headache...\nHow long have you been sleeping? It feels like a long time...\nYou look around. You are laying down in the core of a dead tree, shielded by predators. You look at your clothes, which seem incredibly worn out. Scars in your right forearm look like they were left by teeth. You don’t remember those ever being there. How did you get here? Suddenly, a flashback takes control of your mind. Right before your coma, you remember fighting Drakula, the King of all dragons. He was known to be the only vampire dragon in existence, which made him immortal. Bravely, you defended a town from Drakula’s wrath. You sliced one of Drakula’s wings off, which led him to retreat, but not before a last-ditch effort to bite you in the arm and send you flying into the forest with a powerful tail whip. At over 200 kilometers per hour, your body was projected into the tree where you currently lie, and you lost consciousness. Here you are now. You are a dragon hunter. You are, unbeknownst to you, the Final Dragon Hunter.\nWhat do you want to do next?",
            {{"Exit the tree core", 1}}, // Possible action: Go east to room with id 1
            0, // No XP gain
            {} // No monsters
        },

        {
            1,
            "As you haul yourself out of the tree, you're startled by a cute growl. A baby dragon is hissing at you. How amusing, you hadn't seen one in a very long time. Should you kill it before it lays eggs? Or...let it go?",
            {{"Draw your sword", 2}, {"Ignore the baby dragon", 3}}, // Possible actions: Fight the dragon (go to room 2), or let the dragon go (room 3)
            0, // No XP gain from room
            {}
        },

        {
            2,
            "You engage the dragon as it attempts to be as menacing as possible.",
            {}, 
            0, // No XP gain
            {{"Baby Dragon", 10, 2, "You defeat the baby dragon and gain XP!", 50, 4}} // Monster details: Name, health, attack, description, XP reward, next room ID
        },

       {
            3,
            "The baby dragon looks at you, annoyed you do not view it as a threat, before running for its life towards the bushes, until you can no longer see it. Looking around, you see the forest has more areas to explore. Not too far from you, you can see there is smoke in the sky.\nWhat do you want to do?",
            {{"Explore the forest some more", 4},{"Follow the smoke",6}}, 
            0, // No XP gain
            {} // No monsters
        },

        {
            4,
            "You look around the forest, and notice a clearing you wish to explore some more. You also make note of smoke rising in the sky, not too far from you. After walking in there for a few minutes, you notice a colony of goblins! You could easily provoke one for a quick battle...\nWhat do you want to do?",
            {{"Provoke a goblin", 5}, {"Go see where the smoke is coming from", 6}}, 
            0, // No XP gain
            {} 
        },

        {
            5,
            "You can easily provoke a goblin, who will stupidly accept your challenge. He has no idea you are THE Last Dragon Hunter.\nWhat do you want to do?",
            {{"Provoke a new goblin.", 5},{"Go see where the smoke is coming from",6}},
            0, // No XP gain
            {{"Goblin", 20, 2, "You pummel the goblin until it learns not to mess with you.", 75, 5}} // Monster details: Name, health, attack, description, XP reward, next room ID
        },

        {
            6,
            "After exploring the forest, you march on towards the emanation of smoke. As you walk around, you are surprised to see burnt fields and a chilly absence of life. You don't remember this side of the continent ever looking so grim... What happened here? Regardless, you make your way to the little town of Rutenberg, known for some of the tastiest crops in the continent. As you get there, you are surprised to see few people, most of which seemed sad, or almost frightened. You approach and get a few glances. Some people seem depressed, others are screaming, heralding the end of the world, at the hand of...dragons? You thought there were no dragons left!!! One villager, very vocal, is sitting on a wooden crate, and shouting about a large brown dragon supposedly giving orders to the others, as if it were intelligent enough to be a grandmaster of chess or a software developer. This villager catches your attention.\nWhat do you want to do?",
            {{"Go back to the forest", 4}, {"Talk to the villager", 7}}, 
            0, // No XP gain
            {} // No monsters
        },

        {
            7,
            "The villager gives you a creepy, satisfied smile, as you approach to listen more closely. It was obvious no one had been listening to him for days, or maybe even weeks. This man did not exactly seem sane, as his eyes were exorbitant and bloodshot. \"Closer! Come closer! The wise words of Olaf the Seer are free for all! Let me tell you that the dragons are about to make us meet our doom! One thousand dragons are estimated to be alive right now, burning our crops, killing our men, eating our livestock. We are no match! We should have listened to the elders as they warned us to keep training dragon hunters...but alas! Life was too good! We felt too safe! We did not think the dragons would ever repopulate to do what we did to them! No more...no more dragon hunters at all...\" the man shouts, louder than necessary, since you're the only one listening. It doesn't seem like he will teach you anything new now. However, you notice him holding a newspaper, and the date on it is...200 years from what you expected it to be! Could you really have been knocked out for so long? How are you still alive? The plot thickens...\nWhat do you want to do?",
            {{"Go back to the forest", 4}, {"Explore the town", 8}}, 
            0, // No XP gain
            {} 
        },

        {
            8,
            "You walk around some more...and unfortunately, find a group of women crying, weeping sadly. What could possibly have happened now? This used to be such a proud and joyful little town./nWhat do you want to do now?",
            {{"Go back to the forest", 4},{"Talk to the people crying", 9}}, 
            0, // No XP gain
            {} // No monsters
        },

        {
            9,
            "You walk over to the women, and learn that they are now widows. A small group of medium-sized dragons killed their husbands and took off with the little remaining crops they had left. They seemed organized. It was very scary. The eyes of the widows open wide, when they notice the crest of the dragon hunter on your armor. \"A dragon hunter!!!? Today?!?? I thought they were all extinct!!!\" one woman exclaims herself.\nWhat do you want to do?",
            {{"Keep listening", 10}}, 
            0, // No XP gain
            {} // No monsters
        },

        {
            10,
            "*RRAAAAAAAAHHHHHHHHHHHHHH*/nSuddenly, a large shout emerges from behind you. A tall, seemingly drunk man walks over towards you menacingly, holding his fists up, ready to clobber you. \"Dragon hunters don't exist! You're fooling no one!\" the drunkard exclaims himself, and gets ready to swing.",
            {}, 
            0, // No XP gain
            {{"Drunkard", 7, 5, "You knock the drunkard out, and the town folk cheer for you, including the widows, who didn't ask.", 25, 11}} // Monster details: Name, health, attack, description, XP reward, next room ID
        },

        {
            11,
            "After your easily-fought battle, a calm, old looking villager approaches you. \"Oh dragon hunter, I can't believe my eyes, but I can tell you're the real deal. Please help us. The dragons are taking over the world, and it seems like its safety rests on your broad shoulders. What the widows said is true. Dragons are working together for the first time ever, instead of selfishly thinking of themselves. This organization is extremely powerful, and we stand no chance! The dragons all seem to be directed by this large, brown dragon with red eyes and the largest fangs you've ever seen! He's the ringleader. If you take him out, then surely...the dragons might go back to their selfish ways, and fight each other, giving humanity one last chance...\" You recognize the brown dragon the old man is talking about...It is unmistakenly Drakula...the only vampire dragon known in existence. You must take him out to save the world./What do you want to do?",
            {{"Keep listening to the villager", 12}}, 
            0, // No XP gain
            {} // No monsters
        },

        {
            12,
            "\"I've been observing the dragons for years now, hoping to gain information that someone younger and stronger can use to save us. I'm so glad to have run into you, young dragon hunter (this geezer really has no idea you're older than him). I've followed this large brown dragon, until the edge of his lair, a big castle carved inside of a volcano, surrounded by lava. To gain entrance, you must cross the bridge, but it is often guarded by an armored dragon. Prepare well if you are to go there, young dragon hunter.\" Some younger villagers appear. \"Wow! A real dragon hunter! We need your help! Can you please train us to get better at fighting?\"/nWhat do you want to do now?",
            {{"March towards the volcanic castle", 13},{"Train some villagers for battle",14}},
            0, // No XP gain
            {} // No monsters
        },

        {
            13,
            "You follow the old man's directions, now with a clear mission to save the world. You would have hoped your final dragon hunter friends would still be alive to help you, but you doubt they also magically did not age for 200 years. You walk through another forest to head towards Drakula's volcanic castle.",
            {{"Keep walking on", 16}}, 
            0, // No XP gain
            {} // Monster details: Name, health, attack, description, XP reward, next room ID
        },

        {
            14,
            "You agree to help the villagers a bit. You show them how to wield a sword, or any other similar weapon.\nWhat do you want to do now?",
            {{"Make the villagers do 1000 push-ups", 15}},
            0, // No XP gain
            {} // No monsters
        },

                {
            15,
            "In a few days, you feel like you've done Pareto justice by giving most basics in as little time as possible. However, during your time training the villagers, word has come to you that even more villagers have been burned down by dragons, while you were training...Either way, the practice has been good for you as well. Your body did barely move in 200 years...\nWhat do you want to do now?",
            {{"March towards the volcanic castle", 13}}, 
            150, // No XP gain
            {} // No monsters
        },

        {
            16,
            "While walking through the forest, you notice a draconic scout roaming the area. He has not seen you yet. He is medium-sized, and seems fairly strong.\nWhat do you want to do now?",
            {{"Shout to the dragon that you will kill it", 17}, {"Launch a sneak attack", 17},{"Ignore the dragon and travel around it", 19}}, 
            0, // No XP gain
            {} // Monster details: Name, health, attack, description, XP reward, next room ID
        },

        {
            17,
            "You get the jump on your new \"sparring partner\", who turns around and does its best to prepare to engage you in battle.",
            {},
            0, // No XP gain
            {{"Medium-sized Black Dragon", 20, 4, "You defeat the black dragon and gain XP!", 100, 18}} 
        },

                {
            18,
            "You have slain the black dragon. Do you feel confident enough already to enter the volcanic castle? Or would you rather try to find some more \"sparring partners\"?",
            {{"Keep hunting dragons", 17}, {"Travel towards the volcanic castle", 19}}, 
            0, // No XP gain
            {} // No monsters
        },

        {
            19,
            "As you march on towards the volcanic castle, its majestic beauty stuns you. A large volcano, chiseled by skilled artisans to create a castle, stands tall ahead of you, surrounded by lava. As the old man says, the only entry point to the castle is a narrow bridge that takes you over the lava pit and into the castle. However, it is guarded by a beefy orange dragon, equipped with fine armor, and a large halberd.\nWhat do you want to do now?",
            {{"Battle the dragon head on", 20},{"Cower in fear and go back to the forest", 16}},
            0, // No XP gain
            {} // Monster details: Name, health, attack, description, XP reward, next room ID
        },

        {
            20,
            "As you approach the clearing in front of the bridge, the armored dragon notices you, and points its halberd at you. \"A dragon hunter approaches...I thought you guys were extinct...well nevertheless, they will be...in a few minutes.\" the dragon's voice erupts calmly.",
            {},
            0, // No XP gain
            {{"Bulky Orange Dragon", 40, 2, "You defeat the orange dragon, as it looks at you, not believing it would be bested by a human.", 100, 21}}
        },

        {
            21,
            "After slaying the armored dragon, the coast was clear to enter the beautifully-crafted volcanic castle. As you enter, you notice one extremely long, empty corridor, with grooves on either side. However...you notice a secret passageway in one of the grooves near the entrance.\nWhere do you want to go?",
            {{"Walk down the corridor", 22}, {"Go through the secret passageway", 23}},
            0, // No XP gain
            {} // No monsters
        },

        {
            22,
            "You walk down the long, empty corridor made of red stone. It seems like it will never end.\nWhat do you want to do now?",
            {{"Keep walking", 29}}, 
            0, // No XP gain
            {} 
        },

        {
            23,
            "You go through secret passage you found. It is very dark. It's too bad you don't have a torch...\nWhat do you want to do now?",
            {{"Keep walking", 24}},
            0, // No XP gain
            {} // No monsters
        },

        {
            24,
            "Advancing slowly in the dark, you suddenly feel the ground beneath you crumble, and you fall down into a hole! As you reach the bottom, which must be around 4 meters below, you look around. There are a few dimly lit torches, lighting up cells. You are right outside the cells of a jail, where various human criminals are locked. You are not quite sure why they are here, but they are begging you to free them, in the name of human compassion. They are all covered in tattoos.\nWhat do you want to do now?",
            {{"Free an inmate", 25},{"Follow the underground tunnel", 26}}, 
            0, // No XP gain
            {} // No monsters
        },

        {
            25,
            "After you freed an inmate, he suddenly turns around and pulls out a knife, before trying to take your life.",
            {{"Fight another inmate?", 25}, {"Follow the underground tunnel", 26}}, 
            0, // No XP gain
            {{"Inmate", 22, 3, "You are forced to slay the inmate. Around you, the other inmates also want to be freed, and promise not to hurt you. You notice a tunnel that will extends away from the prison cells.\nWhat do you want to do now?", 75, 25}} // Monster details: Name, health, attack, description, XP reward, next room ID
        },

        {
            26,
            "You follow the dimly-lit tunnel, bringing one of the torches you found in the prison with you. This tunnel is very narrow...it would be bad to run into trouble here...\nWhat do you want to do now?",
            {{"Keep moving forward", 27}},
            0, // No XP gain
            {} // No monsters
        },

        {
            27,
            "As you walk a few more steps forward, you suddenly feel extremely uneasy. You can sense the terrifyingly powerful aura of pure evil haunting the walls around you. You know this feeling very well...It is the power of Drakula, the leader of the dragonkind revolution. You peel your eyes around the corner. There he is...Drakula, your immortal enemy. He. must. be. taken. down.\nYou draw your sword, and get roar at the top of your lungs as you lunge ahead. Drakula slowly gets up. \"I've been expecting you...insect. I accidentally made you immortal when I bit you, 200 years ago...It's time for me to take out the trash.\"",
            {}, 
            0, // No XP gain
            {{"Drakula", 80, 6, "You've finally done it. Your sword is piercing Drakula's body, as he looks at you in pain. \"NO!!! I HAD IT ALL! DRAGONS WERE GOING TO RULE THE WORLD ONCE AGAIN, UNDER MY COMMAND! CURSE YOU DRAGON HUNTER! CURSE YOOOOOUUUUuuuuuuuu\" Drakula said as his voice turned to a dying whisper, and his large body whithered away to dust, leaving nothing but your sword on his throne.", 0, 28}} // No monsters
        },

        {
            28,
            "You look out the window of Drakula's throne room. The dragons serving Drakula in the castle quickly start to disband, no longer bound by their ex-master's otherworldly influence. Some of them even fight together. One thing was certain, the organized attacks commited by dragons were a thing of the past, and humanity had a chance to survive, and exterminate dragons for good this time. A genuine smile reaches your lips. With Drakula's immortal blood rushing through your veins, there would always, for the rest of eternity, be at least one dragon hunter left to defend the world. THE END.",
            {}, 
            0, // No XP gain
            {} 
        },

        {
            29,
            "As you're walking down the long corridor, a shade suddenly jumps out of one of the side grooves, and jumps for your throat!",
            {},
            0, // No XP gain
            {{"Draconic Rogue", 7, 10, "You slay the sneaky dragon!", 100, 30}}
        },

        {
            30,
            "After surviving that first attack, you reach the end of the corridor safely, where it breaks into 2 paths. You can either go left, or go right.\nWhat do you want to do now?",
            {{"Go left", 31}, {"Go right", 32}},
            0, // No XP gain
            {} // No monsters
        },

        {
            31,
            "You select the left path, and find a strengthening potion on a counter! You drink it up and feel yourself getting stronger.\nWhat do you want to do now?",
            {{"Keep walking", 33}}, 
            100, 
            {} 
        },

        {
            32,
            "You select the right path, and find a strengthening potion on a bench! You drink it up and feel yourself getting a bit stronger.\nWhat do you want to do now?",
            {{"Keep walking", 33}},
            50, 
           {}   
        },

        {
            33,
            "As you approach the end of the path, you start to feel like danger is near. The only way to go is forward...\nWhat do you want to do now?",
            {{"Approach...", 27}},
            0, // No XP gain
            {} // No monsters
        }        
    };
    return rooms;
}