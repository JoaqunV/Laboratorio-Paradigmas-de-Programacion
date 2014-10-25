using System;

namespace MultiParadigma
{
	public class CoordenadaEnC
	{
		private int x, y;

		//Constructor vacio
		public CoordenadaEnC()
		{
			this.x = 0;
			this.y = 0;
		}

		//Constructor por parametros
		public CoordenadaEnC(int ladoX, int ladoY)
		{
			this.x = ladoX;
			this.y = ladoY;
		}

		//Propiedades
		int X
		{
			get{return x;}
			set{x = value;}
		}
		int Y
		{
			get{return y;}
			set{y=value;}
		}

		//Metodos
		public CoordenadaEnC sumaDePuntos(int a, int b)
		{
			CoordenadaEnC P = new CoordenadaEnC ();
			P.X = P.x + a;
			P.Y = P.y + b;
			return P;
		}

		//Distancia entre dos puntos
		public double distancia(CoordenadaEnC P)
		{
			double distanc;
			distanc = Math.Sqrt (Math.Pow((X - P.x), 2) + Math.Pow ((Y - P.y), 2));
			return distanc;
		}
	}
}

