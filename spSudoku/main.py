#import main dependancies
import pygame, random, time, shlex
from subprocess import Popen, PIPE



#note: Fix text size!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1

#initialise window:
pygame.init()
pygame.font.init()
size = (540,540)
pygame.display.set_caption("Sudoku")
screen = pygame.display.set_mode(size)
clock = pygame.time.Clock()

#initialise font and generate the information needed for drawing text:
font = pygame.font.SysFont('Calibri', 75, False, False)
playerLetterColour = (0,0,0)

#this is an array that represents the various possible texts to be found in the grid.
#first 10 numbers represent pre-generated values.
#next 10 represent user chosen values
text = [
		font.render(" ",True,playerLetterColour),
		font.render("1",True,playerLetterColour),
		font.render("2",True,playerLetterColour),
		font.render("3",True,playerLetterColour),
		font.render("4",True,playerLetterColour),
		font.render("5",True,playerLetterColour),
		font.render("6",True,playerLetterColour),
		font.render("7",True,playerLetterColour),
		font.render("8",True,playerLetterColour),
		font.render("9",True,playerLetterColour),
		font.render(" ",True,(255,0,0)),
		font.render("1",True,(230,20,0)),
		font.render("2",True,(150,200,0)),
		font.render("3",True,(50,100,120)),
		font.render("4",True,(0,255,0)),
		font.render("5",True,(0,200,50)),
		font.render("6",True,(0,100,250)),
		font.render("7",True,(20,0,200)),
		font.render("8",True,(20,40,150)),
		font.render("9",True,(60,180,0))
		]


#an object to represent each small square in the grid
class Square:
	value = 0
	settable = True

	#initialises the square to a given value.
	def __init__(self,v):
		self.value=v

	#returns the number that represents the current value of the square.
	def get(self):
		return self.value % 10

	#sets the value of the square if it is settable by the user.
	def set(self,v):
		if self.settable:
			self.value = 10+v


	#sets settability
	def setSettability(self,t):
		self.settable = t

	def isBlank(self):
		return self.get() == 0

	def markAsPreGenerated(self):
		self.setSettability(False)
		self.value = self.value-10


	#draws the square at the location x,y.
	def draw(self, x, y):
		screen.blit(text[self.value], [size[0]/9*x+17,size[1]/9*y+2])


#an object to represent the global sudoku grid.
class Grid:
	grid = [[]] #grid drawn in transpose for convenience.
	mBorderSmall = 0
	mBorderLarge = 0
	
	cursorPos = (4,4)
	cursorWidth = 5

	invalidMessage = font.render("Invalid solution!", True, (255,0,0))
	validMessage   = font.render("Valid solution!", True, (20,190,20))
	shouldPrintMessage = False
	boardValid = False

	blankSquaresToHave = 10


	#initialises the grid, setting the border ticknesses.
	def __init__(self, borders, borderl):
		self.mBorderSmall = borders
		self.mBorderLarge = borderl
		self.generateGrid()

	#returns True of the grid is valid. False otherwise (according to Sudoku rules)
	def validateGrid(self):
		for x in range (9):
			for y in range(9):
				if not self.validateSquare(x,y):
					return False
		return True

	def validateSquare(self,x,y):
		return self.grid[x][y].get()!=0 and self.checkHorizontalConstraint(x,y)==1 and self.checkVerticalConstraint(x,y)==1 and self.checkSectionConstraint(x,y)==1

	#Returns 1 if passed game rules. More if too many. Less if no occurance.
	def checkHorizontalConstraint(self, x, y):
		numberOfN = 0
		n = self.grid[x][y].get()
		for i in range (0, 9):
			if self.grid[x][i].get() == n:
				numberOfN = numberOfN+1
		return numberOfN

	#Returns 1 if passed game rules. More if too many. Less if no occurance.
	def checkVerticalConstraint(self, x, y):
		numberOfN = 0
		n = self.grid[x][y].get()
		for i in range (0, 9):
			if self.grid[i][y].get() == n:
				numberOfN = numberOfN+1
		return numberOfN

	#Returns 1 if passed game rules. More if too many. Less if no occurance.
	def checkSectionConstraint(self, x, y):
		sectionCoord = (x//3, y//3)
		n = self.grid[x][y].get()
		numberOfN=0
		for i in range (3*sectionCoord[0], 3*sectionCoord[0]+3):
			for j in range(3*sectionCoord[1], 3*sectionCoord[1]+3):
				if self.grid[i][j].get() == n:
					numberOfN = numberOfN + 1
		return numberOfN


	#returns a list of empty squares in [(x,y)] format
	def findEmptySquares(self):
		out = []
		for i in range(9):
			for j in range(9):
				if self.grid[i][j].get()==0:
					out.append((i,j))
		return out




	###############################################################################################################################

	#returns false if a constraint is broken. Returns true even if not all spaces are filled out.
	def gen_checkConstraints(self, x, y):
		return self.checkHorizontalConstraint(x,y)<2 and self.checkVerticalConstraint(x,y)<2 and self.checkSectionConstraint(x,y)<2

	#similar to solve, but tries to keep things less random.
	def solve(self):
		#Find all empty squares.
		empty = self.findEmptySquares()

		#if nothing to do
		if len(empty) == 0:
			return

		#use recursive function:
		solution =  self.solve_rec(empty)

		#apply to grid
		for i in range(len(solution[1])):
			self.grid[empty[i][0]][empty[i][1]].set(solution[1][i])


	def solve_rec(self, remainingEmpty):

		current = remainingEmpty[0] #should have >1 elements

		#Find possible values that it could take.
		possibleValues = []
		square = self.grid[current[0]][current[1]]

		for i in range(1,10):
			square.set(i)
			if self.gen_checkConstraints(current[0], current[1]):
				possibleValues.append(i)
		square.set(0) #reset to default
		random.shuffle(possibleValues) #should help make it more random

		#impossible
		if len(possibleValues) == 0:
			return (False, [-1]) 

		#if done, should have only one solution:
		if len(remainingEmpty) == 1:
			if len(possibleValues) == 1:
				return (True, [possibleValues[0]])
			else:
				return (False,[-2])

		#If not done but possibility, try possibility n until it's valid.
		for pv in possibleValues:
			square.set(pv)
			recAnswer = self.solve_rec(remainingEmpty[1:])
			square.set(0)
			#if valid, return:
			if recAnswer[0] == True:
				return (True, [pv] + recAnswer[1])
		
		#if reached here, no possibilities
		return (False, [-1])


	#Solves the board using an external C++ solver.
	def externalSolve(self, programName):
		args = "./"+programName
		for i in range(9):
			for j in range(9):
				args = args + " " + str(self.grid[i][j].get())

		a = shlex.split(args)
		proc = Popen(a, stdout=PIPE, stderr=PIPE)
		out, err = proc.communicate()

		emptyMapping = shlex.split(out)

		blankIndex = 0
		for i in range(9):
			for j in range(9):
				if self.grid[i][j].get()==0:
					self.grid[i][j].set(int(emptyMapping[blankIndex]))
					blankIndex = blankIndex+1



		###############################################################################################################################



	#generates a new grid
	def generateGrid(self, freeSpaces = 0):
		self.grid = [[Square(0) for x in range(9)] for y in range(9)]


		t0 = time.time()
		#self.externalSolve("randomsolver")
		self.solve()
		t1 = time.time()

		self.clearRandomSquares(self.blankSquaresToHave)
		self.setPermissions()

		print("Time Taken: " +  str(t1-t0) + " s")


	def clearRandomSquares(self, noToClear):
		noToClear = min(81,noToClear);
		noToClear = max(0,noToClear);

		randCoords = [(x,y) for x in range(9) for y in range(9)]
		random.shuffle(randCoords)

		for i in range(noToClear):
			self.grid[randCoords[i][0]][randCoords[i][1]].set(0)

	def setPermissions(self):
		for i in range(9):
			for j in range(9):
				if not self.grid[i][j].isBlank():
					self.grid[i][j].markAsPreGenerated()

	#draws the borders/lines to convey the grid.
	def drawBorders(self):
		for i in range(1,3):
			pygame.draw.rect(screen, (0,0,0), [i*(size[0]//3)-(self.mBorderLarge//2), 0, self.mBorderLarge, size[1]])
			pygame.draw.rect(screen, (0,0,0), [0, i*(size[0]//3)-(self.mBorderLarge//2), size[0], self.mBorderLarge])

		for i in range (3): #go through squares
			for j in range(1,3): #go through lines
				pygame.draw.rect(screen, (0,0,0), [(size[0]//3)*i + (size[0]//9)*j, 0, self.mBorderSmall, size[1]])
				pygame.draw.rect(screen, (0,0,0), [0, (size[1]//3)*i + (size[1]//9)*j, size[0], self.mBorderSmall])


	#draws the numbers in the grid.
	def drawDigits(self):
		for i in range (9):
			for j in range(9):
				self.grid[j][i].draw(i,j)

	#draws the cursor that represents the curently selected tile.
	def drawCursor(self):
		
		colour = (0, 255, 150)

		pygame.draw.rect(screen, colour, [self.cursorPos[0]*(size[0]//9),self.cursorPos[1]*(size[1]//9),
						self.cursorWidth, size[1]//9]) #vertical 1
		pygame.draw.rect(screen, colour, [(self.cursorPos[0]+1)*(size[0]//9)-self.cursorWidth,self.cursorPos[1]*(size[1]//9),
						self.cursorWidth, size[1]//9]) #vertical 2
		pygame.draw.rect(screen, colour, [self.cursorPos[0]*(size[0]//9),self.cursorPos[1]*(size[1]//9),
						size[1]//9,self.cursorWidth]) #horizontal 1
		pygame.draw.rect(screen, colour, [self.cursorPos[0]*(size[0]//9),(self.cursorPos[1]+1)*(size[1]//9)-self.cursorWidth,
						size[1]//9,self.cursorWidth]) #horizontal 2


	#draws either an error message or a success message, depending on whether the grid validity flag is set to True.
	def drawAnswerConfirmation(self):
		xboxdivisor = 8
		yboxdivisor = 4

		#source: http://stackoverflow.com/questions/6339057/draw-a-transparent-rectangle-in-pygame
		s = pygame.Surface((size[0]-size[0]/(xboxdivisor/2),
							size[1]-size[1]/(yboxdivisor/2)))  # the size of your rect
		s.set_alpha(220)                # alpha level
		s.fill((10,10,80))           # this fills the entire surface
		screen.blit(s, (size[0]/xboxdivisor,size[1]/yboxdivisor))    # (0,0) are the top-left coordinates


		if self.boardValid:
			screen.blit(self.validMessage, [95,size[1]/2-30])
		else:
			screen.blit(self.invalidMessage, [75,size[1]/2-30])


	#validates the grid and triggers a message to confirm/deny validity.
	#resets game if won and pressed again.
	def submitAnswer(self):
		if self.shouldPrintMessage:
			if self.boardValid == True:
				self.generateGrid()

		self.shouldPrintMessage = not self.shouldPrintMessage
		if self.shouldPrintMessage:
			self.boardValid = self.validateGrid()


	#Sets the currently selected tile to the given value.
	def setTileAtCursor(self, newValue):
		if self.shouldPrintMessage:
			return
		self.grid[self.cursorPos[1]][self.cursorPos[0]].set(newValue)


	#updates the currently selected tile based on the mouse location.
	def updateCursor(self, screenPos):
		if self.shouldPrintMessage:
			return
		self.cursorPos = (screenPos[0]//(size[0]//9), screenPos[1]//(size[1]//9))

	#moves the currently selected tile, keeping it inside the sudoku grid.
	def moveCursor(self, directionX, directionY):
		if self.shouldPrintMessage:
			return
		self.cursorPos = (self.cursorPos[0]+directionX, self.cursorPos[1]+directionY)
		if self.cursorPos[0] < 0 or self.cursorPos[1] < 0 or self.cursorPos[0] > 8 or self.cursorPos[1] > 8:
			self.moveCursor(-directionX, -directionY)


	#draws all the components of the grid.
	def draw(self):

		width = size[0]/9
		height = size[1]/9
		for i in range(9):
			for j in range(9):
				pygame.draw.rect(screen, (255,255,255), [i*width, j*height, width,height])
		self.drawBorders()
		self.drawCursor()
		self.drawDigits()

		if self.shouldPrintMessage:
			self.drawAnswerConfirmation()



#main game execution loop:

done = False #should we stop?

grid = Grid(4,8) #the grid defind above is created

#main loop
while not done:

	#check for user input and call appropriate functions.

	for event in pygame.event.get():
		if event.type == pygame.QUIT:
			done = True
		elif event.type == pygame.MOUSEBUTTONDOWN:
			grid.updateCursor(pygame.mouse.get_pos())
		elif event.type == pygame.KEYDOWN:
			if event.key == pygame.K_1:
				grid.setTileAtCursor(1)
			elif event.key == pygame.K_2:
				grid.setTileAtCursor(2)
			elif event.key == pygame.K_3:
				grid.setTileAtCursor(3)
			elif event.key == pygame.K_4:
				grid.setTileAtCursor(4)
			elif event.key == pygame.K_5:
				grid.setTileAtCursor(5)
			elif event.key == pygame.K_6:
				grid.setTileAtCursor(6)
			elif event.key == pygame.K_7:
				grid.setTileAtCursor(7)
			elif event.key == pygame.K_8:
				grid.setTileAtCursor(8)
			elif event.key == pygame.K_9:
				grid.setTileAtCursor(9)
			elif event.key == pygame.K_0:
				grid.setTileAtCursor(0)
			elif event.key == pygame.K_UP or event.key == pygame.K_w:
				grid.moveCursor(0,-1)
			elif event.key == pygame.K_DOWN or event.key == pygame.K_s:
				grid.moveCursor(0,1)
			elif event.key == pygame.K_LEFT or event.key == pygame.K_a:
				grid.moveCursor(-1,0)
			elif event.key == pygame.K_RIGHT or event.key == pygame.K_d:
				grid.moveCursor(1,0)
			elif event.key == pygame.K_RETURN:
				grid.submitAnswer()


	#draw and continue:
	screen.fill((0,0,0))
	grid.draw()
	pygame.display.flip()
	clock.tick(60)


#shutdown pygame:
pygame.quit()