# 🃏 Juego de Cartas por Rondas en C++

Un juego por turnos en **C++** para dos jugadores, donde cada jugador compite usando cartas con **puntos** y **habilidades especiales**. Gana quien se impone en 2 de 3 rondas, combinando estrategia y algoritmos.

---

##  Objetivo del Juego

- Jugar hasta **3 rondas**.
- En cada ronda, puedes jugar **hasta 4 cartas**.
- Gana la ronda quien **sume más puntos**.
- cada carta tiene diferentes puntos algunos te quitan puntos pero tienen habilidades.
- Algunas cartas tienen **habilidades especiales** que modifican el juego.
- Gana la partida quien gane **2 rondas** o tenga más puntos totales.

---

##  Mecánica

- Cada jugador recibe **10 cartas aleatorias**.
- En cada turno se muestran **4 cartas disponibles**.
- Puedes **usar una carta de las 4**.
- en el cuarto turno **puedes elegir si quieres usar la carta o guardartela**
---

## 💡 Habilidades Especiales

| Habilidad           | Descripción                                                              |
|---------------------|--------------------------------------------------------------------------|
| `duplicador mayor`  | Duplica los puntos de tu carta con más puntos                            |
| `duplicador menor`  | Duplica los puntos de tu carta con menos puntos mayor a 0                |
| `divisor`           | Divide por 2 los puntos de la carta más fuerte del oponente              |
| `removedor`         | Gira tu mazo (lista circular), cambiando el orden de tus cartas          |
| `ordenador`         | Ordena tus cartas de mayor a menor usando **burbuja**                    |

---
---
##  Nivel Desarrollador

### 📁 Archivos del Proyecto

- **`main.cpp`**  
  Punto de entrada del programa. Crea una instancia de la clase `Partida` y comienza el juego.

- **`Partida.cpp`**  
  Lógica principal del juego. Controla el flujo de rondas, puntuación y uso de cartas.

- **`Carta.h`**  
  Define la clase `Carta`, con atributos como nombre, puntos y habilidad especial.

- **`ListaCircular.cpp`**  
  Implementación de la estructura de lista circular doble usada para el mazo de cada jugador.

- **`Nodo.cpp`**  
  Nodo doble que se usa como unidad de la lista circular.

- **`Lector_cartas.cpp`**  
  Lee las cartas desde un archivo de texto (`cartas.txt`) y las convierte en objetos `Carta`.

- **`cartas.txt`**  
  Archivo de entrada con la información de todas las cartas disponibles para el juego.


---
##  `main.cpp`
Archivo principal del proyecto.

- Crea una instancia de la clase `Partida`.
- Llama al método `partida()` para iniciar el juego.

---

##  `Partida.cpp`
Clase principal que controla la ejecución del juego: preparación, desarrollo de rondas y puntuaciones.

### 🧮 Atributos de la clase `Partida`

| Variable              | Tipo          | Descripción                                              |
|-----------------------|---------------|----------------------------------------------------------|
| `Carta* array_cartas` | puntero       | Array dinámico de cartas cargadas desde el archivo `.txt` |
| `int contador`        | entero        | Número total de cartas cargadas                          |
| `lector_cartas lector`| objeto        | Objeto que lee las cartas del archivo                    |
| `ListaCircular lista_jugador1` | objeto | Mazo del jugador 1                                       |
| `ListaCircular lista_jugador2` | objeto | Mazo del jugador 2                                       |
| `float puntos_total_j1/j2` | float    | Puntos acumulados por cada jugador durante la partida    |
| `float puntos_ronda_j1/j2`| float     | Puntos obtenidos en la ronda actual                      |
| `int rondas_j1/j2`    | entero        | Rondas ganadas por cada jugador                          |

###  Métodos principales

#### `int partida()`
- Controla el flujo general del juego.
- Reparte cartas, lanza rondas, muestra mensajes y determina el ganador.

#### `int asignar_cartas(ListaCircular& lista)`
- Inserta 10 cartas aleatorias en la lista recibida como parámetro.
- La aleatoriedad se basa en la hora del sistema (`srand(time(0))`).

#### `int ronda()`
- Controla una ronda completa (4 turnos por jugador).
- Muestra las cartas disponibles y permite jugar o reservar cartas.
- Aplica las habilidades especiales de cada carta usada.

#### `void habilidades(Carta carta, ListaCircular& lista, int i)`
- Identifica la habilidad de la carta jugada y aplica su efecto sobre la lista.
- Efectos como duplicar, dividir, ordenar o girar el mazo.

#### `int buscar_indice_max(ListaCircular& lista)`
- Devuelve el índice de la carta con más puntos en la lista.

#### `int buscar_indice_min(ListaCircular& lista)`
- Devuelve el índice de la carta con menor puntaje **mayor que 0** (para evitar habilidades).

#### `int verificar_ganador()`
- Comprueba si un jugador ha ganado 2 rondas.
- Retorna `1` si hay ganador, `0` si la partida continúa.

#### `void instrucciones()`
- Muestra al usuario las reglas del juego, los turnos y las habilidades disponibles.

  ---
  ##  `Lector_cartas.cpp`

Este archivo contiene la implementación de la clase `lector_cartas`, encargada de leer las cartas desde un archivo de texto (`cartas.txt`) y cargarlas en memoria para usarlas en el juego.

### 🔧 Funciones principales

#### `Carta* leer_cartas()`
- Abre el archivo `cartas.txt`.
- Lee línea por línea el contenido, separando cada carta por `;`.
- Crea un array dinámico de objetos `Carta` y lo devuelve.
- Omite líneas vacías o comentadas (que empiezan con `#`).
- Utiliza `stringstream`, `getline` y `stoi` para parsear los datos.

#### `int get_contador()`
- Devuelve la cantidad de cartas leídas y almacenadas.

#### `Carta* get_cartas()`
- Devuelve el puntero al array de cartas cargadas.

#### `int mostrar_cartas()`
- Imprime por pantalla todas las cartas leídas del archivo usando el método `mostrar()` de cada carta.

###  Variables importantes

| Variable         | Tipo      | Descripción                                 |
|------------------|-----------|---------------------------------------------|
| `Carta* array_cartas` | Puntero | Array dinámico que almacena las cartas       |
| `int contador`   | Entero    | Número de cartas válidas leídas del archivo |
| `int capacidad`  | Entero    | Tamaño reservado inicialmente para el array |

### 📝 Formato de entrada esperado (`cartas.txt`)

Cada carta debe estar en una línea con el siguiente formato: nombre;puntos;habilidad
## 📄 `Carta.h`

Define la clase `Carta`, que representa una carta dentro del juego. Cada carta tiene un nombre, un valor de puntos y una habilidad especial.

### 🧱 Atributos

| Atributo              | Tipo     | Descripción                                             |
|------------------------|----------|---------------------------------------------------------|
| `nombre`              | `string` | Nombre de la carta (ej. "duplicador mayor")             |
| `puntos`              | `int`    | Valor de la carta. Puede ser positivo, negativo o cero. |
| `habilidad_especial`  | `string` | Habilidad asociada a la carta (o `"ninguno"`)           |

---

### 🔧 Métodos públicos

#### `Carta(string nombre, int puntos, string habilidad)`
Constructor que crea una carta con nombre, puntos y habilidad.

#### `Carta()`
Constructor por defecto. Inicializa una carta vacía sin habilidad y con 0 puntos.

#### `void mostrar() const`
Imprime por pantalla el nombre, los puntos y la habilidad de la carta.

---

##  `ListaCircular.cpp`

Implementa la clase `ListaCircular`, una estructura de datos circular doblemente enlazada para representar el mazo de cada jugador.

Esta estructura permite insertar, eliminar, girar y ordenar cartas de forma eficiente, simulando un mazo cíclico.

---

###  Atributos privados

| Atributo | Tipo   | Descripción                                               |
|----------|--------|-----------------------------------------------------------|
| `Nodo* lista` | Puntero | Apunta al primer nodo de la lista circular              |
| `int n`       | Entero  | Almacena la cantidad de elementos en la lista           |

---

### 🔧 Métodos públicos

#### `ListaCircular()`
Constructor. Inicializa una lista vacía.

#### `Carta getCarta(int posicion)`
Devuelve la carta ubicada en la posición indicada.

#### `void setCarta(int posicion, const Carta& nuevaCarta)`
Reemplaza la carta en una posición con una nueva carta.

#### `int getN()`
Devuelve la cantidad de cartas actualmente en la lista.

#### `void insertar(int posicion, const Carta& nuevaCarta)`
Inserta una nueva carta en la posición indicada.  
Actualiza los punteros para mantener la circularidad.

#### `void eliminar(int posicion)`
Elimina la carta en la posición indicada y libera la memoria del nodo.

#### `void girar(int p)`
Rota la lista `p` posiciones hacia adelante (si `p > 0`) o hacia atrás (si `p < 0`).

#### `void mostrar()`
Imprime todas las cartas de la lista utilizando el método `mostrar()` de `Carta`.

#### `void ordenar()`
Ordena las cartas por puntos de **mayor a menor** usando el algoritmo **burbuja**.

#### `~ListaCircular()`
Destructor. Libera la memoria de todos los nodos en la lista circular.


---



