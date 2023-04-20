package serial;

import java.io.*;

class Serializer {
	private String filepath;
	private File boundFile;

	private PrintStream stream;

	public Serializer(String path) {
		filepath = path;

		boundFile = new File(filepath);

		try {
			stream = new PrintStream(boundFile);
		} catch(Exception err) {
			System.out.println(err.getMessage());
		}
	}

	void serialize_nl(Point p, boolean newline) {
		stream.print(Float.toString(p.getX()) + " " + Float.toString(p.getY()));

		if(newline) {
			stream.print("\n");
		}
	}

	void serialize(Point p) {
		serialize_nl(p, true);
	}

	void serialize(Line l) {
		serialize_nl(l.p1, false);
		stream.print(" ");
		serialize_nl(l.p2, false);
	}
}
