# q-learning car (Chili-Framework 2016)

Proyecto para implementar un modelo de ML que aprenda a conducir derrapando como un pto loco. El coche puede ir en 4 direcciones, más que nada por no tener que dibujar 
rectángulos girados que es mucho peor de lo que suena. 

- Utilizando el Framework de Chili (https://wiki.planetchili.net/index.php/Beginner_C%2B%2B_Game_Programming_Tutorial_0). Podria 
usar una versión más nueva del motor y seguramente sería más rápido y puede que hasta más fácil. 
- Al ser DirectX solo funciona en Windows. Y con Visual Studio (facilita la compilación con las sln, etc). Si no, difícil. Cómo no.
- Básicamente todo el código en inglés es el del Framework y el español el mío.
- De momento todo lo gráfico se hace con PutPixel, poniendo cada pixel individualmente... Un poco ridículo, ya lo mejoraré si hace falta.

## Hecho:
- "Físicas" del coche (acelera, decelera, gira 90º y derrapa).
- Clases Forma, Rectangulo, Recta y su forma de dibujarlas y colocarlas en pantalla (con el raton).
- Comunicación a través de los eventos del ratón (ha sido más descifrar cómo hacerlo).
- Controles: De momento se maneja con las flechitas, el ratón dibuja formas (se cambian con la q) y el espacio las borra.

## Queda:
- Colisiones entre formas.
- Generar proceduralmente escenarios medianamente aleatorios para el aprendizaje.
- Dar vida al coche (que se mueva solo según sus decisiones).
- Implementar el Q-learning D:
