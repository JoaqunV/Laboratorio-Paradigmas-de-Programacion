using System;

namespace MultiParadigma
{
	public class Coordenada
	{
		private int x, y;
		//Constructor en blanco
		public Coordenada()
		{
			this.x = 0;
			this.y = 0;
		}
		//Constructor con parametros
		public Coordenada(int ladoX, int ladoY)
		{
			this.x = ladoX;
			this.y = ladoY;
		}
		//Gets
		public int setLadoX()
		{
			return x;
		}
		public int setLadoY()
		{
			return y;
		}
		//Sets
		public void setCoordenadaX(int ladoX)
		{
			this.x = ladoX;
		}
		public void CoordenadaY(int ladoY)
		{
			this.y = ladoY;
		}


	}
}

