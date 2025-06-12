-- 1. 
areaCirculo :: Float -> Float
areaCirculo r = pi * r * r

-- 2. 
juros :: Float -> Float -> Float -> Float
juros c i t = c * i * t

-- 3. 
maior :: Int -> Int -> Int
maior x y = if x > y then x else y

-- 4. 
classificarNumero :: Int -> Int
classificarNumero x
  | x > 0 = 1
  | x < 0 = -1
  | otherwise = 0

-- 5.
delta :: Float -> Float -> Float -> Float
delta a b c = b * b - 4 * a * c

bhaskara :: Float -> Float -> Float -> (Float, Float)
bhaskara a b c = ((-b + sqrt d) / (2 * a), (-b - sqrt d) / (2 * a))
  where d = delta a b c

-- 6. 
fatorial :: Int -> Int
fatorial 0 = 1
fatorial n = n * fatorial (n - 1)

-- 7. 
mdc :: Int -> Int -> Int
mdc x 0 = x
mdc x y = mdc y (x mod y)

-- 8. 
fibonacci :: Int -> Int
fibonacci 0 = 0
fibonacci 1 = 1
fibonacci n = fibonacci (n - 1) + fibonacci (n - 2)

-- 9. 
soma :: [Int] -> Int
soma [] = 0
soma (x:xs) = x + somaLista xs

-- 10. 
menorLista :: [Int] -> Int
menorLista [x] = x
menorLista (x:xs) = min x (menorLista xs)

-- 11. 
fibonacciAte :: Int -> [Int]
fibonacciAte n = map fibonacci [0..n]

-- 12. 
estaNaLista :: Int -> [Int] -> Bool
estaNaLista _ [] = False
estaNaLista n (x:xs)
  | n == x = True
  | otherwise = estaNaLista n xs

-- 13.
ordenado :: Int -> [Int] -> [Int]
ordenado x [] = [x]
ordenado x (y:ys)
  | x <= y = x : y : ys
  | otherwise = y : ordenado x ys

ordenarLista :: [Int] -> [Int]
ordenarLista [] = []
ordenarLista (x:xs) = ordenado x (ordenarLista xs)

-- 14. 
intercalar :: [a] -> [a] -> [a]
intercalar [] [] = []
intercalar (x:xs) (y:ys) = x : y : intercalar xs ys
intercalar _ _ = error "Listas de tamanhos diferentes"