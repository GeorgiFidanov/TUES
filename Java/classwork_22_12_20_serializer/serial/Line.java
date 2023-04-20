package serial;

import java.lang.*;

class Line {
	public Point p1;
	public Point p2;

	public Line(Point _p1, Point _p2) {
		p1 = _p1;
		p2 = _p2;
	}

	public float getLength() {
		float dx = p1.getX() - p2.getX();
		float dy = p1.getY() - p2.getY();

		return (float)Math.sqrt(dx * dx + dy * dy);
	}

}
