# Black Jack by Kuramais
import random as rd

winner, turn = None, 1

class Hand:
    def __init__(self, number):
        self.number = [number]
        self.cadidate = True
    
    def draw(self):
        pick = int(rd.randrange(2,11,1))
        self.number.append(pick)

    def chkifexceed(self):
        self.cadidate = False if sum(self.number) > 21 else True
        return True if sum(self.number) > 21 else False
    
    def chkbot(self):
        if sum(self.number) < 14:
            return False
        else: return True if sum(self.number) > 17 else False

yrhand = Hand(int(rd.randrange(2,11,1)))
ophand = Hand(int(rd.randrange(2,11,1)))

print("\n>>> d for draw, r for reval <<<")

while True:
    print(f"\nturn {turn}\nyours: {yrhand.number}")

    match input("sel :"):
        case 'd':
            yrhand.draw()
            print(f"U draw {yrhand.number[-1]}!")
            if ophand.chkbot():
                break
            else : ophand.draw()
        case 'r':
            if not ophand.chkbot():
                ophand.draw()
            break
        case _ :
            print("error, I will draw for you :)")
            yrhand.draw()
            print(f"U draw {yrhand.number[-1]}!")
            if ophand.chkbot():
                break
            else : ophand.draw()

    if yrhand.chkifexceed() or ophand.chkifexceed():
        break

    turn += 1

if winner == None:
    yrhand.chkifexceed()
    ophand.chkifexceed()
    if not yrhand.cadidate or not ophand.cadidate:
        if yrhand.cadidate:
            winner = "You"
        else: winner = "Bot"
    else:
        if sum(yrhand.number) > sum(ophand.number):
            winner = "You"
        elif sum(yrhand.number) < sum(ophand.number):
            winner = "Bot"
        else : winner = "Draw"

print(f"winner is {winner}, with score {sum(ophand.number) if winner == "Bot" else sum(yrhand.number)} : {sum(yrhand.number) if winner == "Bot" else sum(ophand.number)}")