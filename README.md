# 🃏 Juego de Cartas por Rondas en C++

Un juego por turnos en **C++** para dos jugadores, donde cada jugador compite usando cartas con **puntos** y **habilidades especiales**. Gana quien se impone en 2 de 3 rondas, combinando estrategia y algoritmos.

---

## 🎯 Objetivo del Juego

- Jugar hasta **3 rondas**.
- En cada ronda, puedes jugar **hasta 4 cartas**.
- Gana la ronda quien **sume más puntos**.
- Algunas cartas tienen **habilidades especiales** que modifican el juego.
- Gana la partida quien gane **2 rondas** o tenga más puntos totales.

---

## 🧠 Mecánica

- Cada jugador recibe **10 cartas aleatorias**.
- En cada turno se muestran **4 cartas disponibles**.
- Puedes **usar una carta o saltar** un turno.
- Algunas cartas usan algoritmos como:
  - 🔁 Ordenamiento burbuja
  - 🔍 Búsqueda del mayor o menor puntaje
  - 🔄 Giro de lista circular
  - 💥 Modificaciones directas a la mano

---

## 💡 Habilidades Especiales

| Habilidad           | Descripción                                                              |
|---------------------|--------------------------------------------------------------------------|
| `duplicador mayor`  | Duplica los puntos de tu carta con más puntos                           |
| `duplicador menor`  | Duplica los puntos de tu carta con menos puntos (> 0)                   |
| `divisor`           | Divide por 2 los puntos de la carta más fuerte del oponente             |
| `removedor`         | Gira tu mazo (lista circular), cambiando el orden de tus cartas         |
| `ordenador`         | Ordena tus cartas de mayor a menor usando **burbuja**                  |

---

## 🗂️ Estructura del Proyecto

