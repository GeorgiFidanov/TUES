package serial;

public class Main {
	public static void main(String args[]) {
		Point p1 = new Point(2.0f, 2.0f);
		Point p2 = new Point(10.0f, 5.0f);

		Line l = new Line(p1, p2);

		System.out.println(l.getLength());

		/*Serializer s = new Serializer("out.txt");

		s.serialize(l);
		s.serialize(p1);
		s.serialize(p2);*/

		Deserializer ds = new Deserializer("out.txt");

		ds.parse();

		System.out.println(ds.loadPoint());
		System.out.println(ds.loadPoint());
	}
}
