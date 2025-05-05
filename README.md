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
## main.cpp
-simplemente se crea y inicia una clase partida llamando a la funcion principal
---
## partida.cpp
- clase encargada del funcionamiento de la partida
- -------**MEtODOS**-------
         - int partida()
                    -gestina la llamada a las funciones ademas del curso de la partida mensajes y en general todo lo necesario para el correcto transcruso de la partida
         - int asignar_cartas(ListaCircular& lista)
                    -se le pasa una lista y se le insertan 10 cartas aleatorias de las que hemos añadido en el txt la aleatoriedad varia en funcion de la hora
         - int ronda()
                    -gestion la ronda haciendo un bucle que dura 4 veces ya que son los turnos de cada jugador y mostrando las cartas en funcion de la ronda 
         - int habilidades(Carta carta,ListaCircular& lista,int i)
                    -esta funcion se encarga de gestionar las habilidades comparando el nombre de las cartas y haciendo las llamadas a las funciones 
         - int buscar_indice_max(ListaCircular& lista)
                    - busca el indice de la carta con mayor puntuacion y devuelve el indice 
         - int buscar_indice_min(ListaCircular& lista)
                    -busca el indice de la carta con la puntuacion mas baja y que sea mayor a 0 para evitar cojer cartas especiales y te lo devuelve 
         - int verificar_ganador()
                    - verifica que jugador gana la partida usando rondas totales
         - void instrucciones()
                    -esta funcion se encarga de mostrar las instrucciones del juego

