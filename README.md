## Descripción
Programa en C++ que genera todas las combinaciones posibles de tamaño r a partir de n elementos (grupos de letras o palabras) ingresados por el usuario. El programa muestra las combinaciones generadas en la consola, las ordena lexicográficamente y las guarda en un archivo CSV.

## Autor
Miguel Angel Nuñez Holguin-

## Requisitos del sistema
Hardware
Procesador: Intel de doble núcleo
Memoria RAM: 16 GB
Disco duro: 256 GB
Software
Compilador de C++:
Code::Blocks
Sistema Operativo:
Windows 10/11

## Instrucciones de compilación y ejecución
1. Compile el programa usando g++ (u otro compilador C++ compatible):
   ```
   g++ -std=c++11 -o generador_combinaciones main.cpp
   ```
2. Ejecute el programa generado:
   ```
   ./generador_combinaciones
   ```
3. Siga las instrucciones en pantalla para ingresar los grupos de letras o palabras separados por comas y el tamaño de combinación deseado.

## Explicación del algoritmo
El programa implementa un algoritmo para generar todas las combinaciones de tamaño r a partir de n elementos distintos, también conocido como "combinaciones sin repetición" o "r-combinaciones". Este proceso sigue estos pasos:

1. Se solicita al usuario ingresar una lista de elementos (palabras o grupos de letras) separados por comas.
2. Se pide al usuario especificar el tamaño r de las combinaciones a generar.
3. El algoritmo inicializa un vector de índices con los primeros r números (0,1,2,...,r-1).
4. Se genera la primera combinación usando estos índices para seleccionar elementos del conjunto original.
5. Se avanza sistemáticamente a la siguiente combinación incrementando el índice más a la derecha que pueda incrementarse sin exceder su valor máximo permitido.
6. El proceso continúa hasta que todos los índices alcanzan sus valores máximos, indicando que se han generado todas las combinaciones posibles.

La complejidad temporal del algoritmo es O(n choose r), ya que debe generar todas las combinaciones posibles.

## Orden Lexicográfico
El orden lexicográfico es una generalización del orden alfabético utilizado en diccionarios. En este programa:

1. Primero se generan las combinaciones en orden sistemático según el algoritmo combinatorio.
2. Luego, estas combinaciones se almacenan en un vector y se ordenan lexicográficamente usando `std::sort`.
3. El orden lexicográfico compara las combinaciones elemento por elemento, similar a cómo se comparan palabras letra por letra en un diccionario.

Por ejemplo, para las combinaciones (a,b), (a,c), (b,c), el orden lexicográfico sería: (a,b) < (a,c) < (b,c).

## Validación de entrada
El programa implementa las siguientes validaciones:
- Verifica que n (número de elementos) sea al menos 1
- Comprueba que r (tamaño de combinación) sea no negativo y no mayor que n (0 ≤ r ≤ n)
- Elimina espacios en blanco de las entradas del usuario
- Ignora entradas vacías en la lista de elementos

## Formato de salida
### Consola:
- Muestra los grupos ingresados
- Lista las combinaciones generadas en formato (a<b<c)
- Muestra las combinaciones ordenadas lexicográficamente
- Presenta información final: número total de combinaciones generadas, número teórico según C(n,r) y nombre del archivo generado

### Archivo CSV:
- Genera un archivo nombrado "combinaciones_n_r.csv" donde n y r son los valores utilizados
- Cada línea contiene una combinación, con los elementos separados por comas
- Por ejemplo: a,b,c

## Verificación C(n,r)
El programa verifica la correctitud del proceso de generación mediante:
1. Cálculo teórico del número de combinaciones usando la fórmula del coeficiente binomial C(n,r)
2. Conteo del número real de combinaciones generadas
3. Comparación de ambos valores, que deben coincidir, mostrando esta información al usuario

La función `calcularBinomial()` implementa el cálculo del coeficiente binomial de manera eficiente, evitando desbordamientos mediante operaciones incrementales.
