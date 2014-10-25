using System;

namespace MultiParadigma
{
	public class M
	{
		static void Main(string[] args)
		{
			CoordenadaEnC Punto = new CoordenadaEnC();
			CoordenadaEnC Punto2 = new CoordenadaEnC (1, 1);
			Console.WriteLine("Distancia de punto (2,3): " + Punto.distancia(Punto2));
		}
	}
}