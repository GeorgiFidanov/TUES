package serial;

import java.util.*;
import java.util.regex.Pattern;
import java.io.File;

class Deserializer {
	private String filepath;
	private File file;
	private Scanner sc;

	private ArrayList<Point> points;
	private ArrayList<Line> lines;

	private int pix;
	private int lix;

	public Deserializer(String path) {
		filepath = path;
		file = new File(path);

		points = new ArrayList<Point>();
		lines = new ArrayList<Line>();
		
		pix = 0;
		lix = 0;

		try {
			sc = new Scanner(file);
		} catch(Exception err) {
			System.out.println(err.getMessage());
		}
	}

	public void parse() {
		while(sc.hasNextLine()) {
			String line = sc.nextLine();
			Scanner s = new Scanner(line);

			int count = 0;
			float[] coords = new float[4];

			while(s.hasNextFloat()) {
				coords[count++] = sc.nextFloat();
			}

			if(count == 2) {
				points.add(new Point(coords[0], coords[1]));
			}

			if(count == 4) {
				Point p1 = new Point(coords[0], coords[1]);
				Point p2 = new Point(coords[2], coords[3]);

				Line l = new Line(p1, p2);

				lines.add(l);
			}
		}
	}

	public Point loadPoint() {
		Point p =  points.get(pix);

		pix++;

		return p;
	}

	public Line loadLine() {
		Line p =  lines.get(lix);

		lix++;

		return p;
	}
}
