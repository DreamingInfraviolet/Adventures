# This script generates a theorem for them Z3 SAT solver. The output of this program
# is designed to be the input for http://rise4fun.com/z3
# The output of z3 is the coordinates of the queens for a solution to the N Queen problem :)


#Prints an assert statement
def zassert(x):
    print("( assert ( {} ) )".format(x))

#Prints a declaration
def zdeclare(x, type="Int"):
    print("( declare-const {} {} )".format(x,type))

#Generates a Z3 proof.
# N = number of queens.
# G = grid size (8 = chess board)
def generate(N, G) :
    zdeclare("N") #Nuber of queens
    zdeclare("G") #Board size
    zassert("= N {}".format(N)) #Init N
    zassert("= G {}".format(G)) #Init G

    #Generate queen names
    queensX = ["P{}_x".format(n) for n in range(0, N) ]
    queensY = ["P{}_y".format(n) for n in range(0, N) ]

    #Declare queens
    for i in range(N):
        zdeclare(queensX[i])
        zdeclare(queensY[i])

    #For each queen Position
    for P in range(N):

        #Assert bounds
        zassert(">= {} 0".format(queensX[P]))
        zassert(">= {} 0".format(queensY[P]))
        zassert("<  {} G".format(queensX[P]))
        zassert("<  {} G".format(queensY[P]))
        
       

        for PP in range(P+1, N):
             #Assert Horizontal and Vertical Uniqueness
            zassert("not ( or (= {ax} {bx} ) (= {ay} {by} ) )"
                            .format(ax=queensX[P], bx=queensX[PP], ay=queensY[P], by=queensY[PP]))

            #Assert Diagonal uniqueness
            # / angle
            zassert("not ( exists (( t Int )) ( and ( and ( and ( = (+ {ax} t) {bx} ) ( >= (+ {ax} t) 0 ) ) ( < (+ {ax} t) G ) )  ( and ( and ( = (+ {ay} t) {by} ) ( >= (+ {ay} t) 0 ) ) ( < (+ {ay} t) G ) ) ) )"
                    .format(ax=queensX[P], bx=queensX[PP], ay=queensY[P], by=queensY[PP]))
                
            # \ angle
            zassert("not ( exists (( t Int )) ( and ( and ( and ( = (+ {ax} t) {bx} ) ( >= (+ {ax} t) 0 ) ) ( < (+ {ax} t) G ) )  ( and ( and ( = (- {ay} t) {by} ) ( >= (- {ay} t) 0 ) ) ( < (- {ay} t) G ) ) ) )"
                    .format(ax=queensX[P], bx=queensX[PP], ay=queensY[P], by=queensY[PP]))

    

    print("(check-sat)")
    print("(get-model)")

#Generate proof for 8 queens on an 8x8 grid
generate(8,8)