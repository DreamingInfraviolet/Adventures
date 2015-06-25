data Fun = Bowling 
		 | Gaming
		 | Kissing
		 | Jumping
	deriving Show

data FailableDouble = Failure
			   | OK Double
	deriving Show

data Weekday = Monday
			 | Tuesday
			 | Wednesday
			 | Thursday
			 | Friday
			 | Saturday
			 | Sunday
	deriving Show

data Day = Day String Weekday
		 | Funday String Weekday Fun
	deriving Show

safeDiv :: Double -> Double -> FailableDouble
safeDiv _ 0 = Failure
safeDiv x y = OK (x/y)

failureToZero :: FailableDouble -> Double
failureToZero Failure = 0
failureToZero (OK x) = x

brent :: Day
brent = Funday "Heyo" Monday Gaming

--getFun :: Day -> String
--getFun day@(Funday _ _ fun) = "The fun of " ++ day ++ " is " ++ fun

str = "Hello"

main = do
	print $ 