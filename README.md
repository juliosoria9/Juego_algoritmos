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
## NIVEL DESARROLLADOR

|--------------------**ARCHIVOS**--------------------|

├── main.cpp               # Punto de entrada al juego
├── Partida.cpp            # Lógica principal del juego y control de flujo
├── Carta.h                # Clase Carta con atributos y métodos
├── ListaCircular.cpp      # Estructura dinámica circular para las manos
├── Nodo.cpp               # Nodo doble para la lista circular
├── Lector_cartas.cpp      # Lee cartas desde archivo .txt
├── cartas.txt             # Archivo de datos de entrada con las cartas

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
| `int puntos_total_j1/j2` | entero     | Puntos acumulados por cada jugador durante la partida    |
| `int puntos_ronda_j1/j2`| entero     | Puntos obtenidos en la ronda actual                      |
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


