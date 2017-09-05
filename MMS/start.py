from Match import Match,readPlayerFile

playerList=readPlayerFile("player.txt")
match=Match("male.txt","female.txt")
for p in playerList:
    match.kick_start(p)
