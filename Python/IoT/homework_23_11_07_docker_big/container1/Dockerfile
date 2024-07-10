FROM python

WORKDIR /app

COPY . .

RUN pip install --upgrade pip
RUN pip install -r requirements.txt 

EXPOSE 5000

CMD ["python", "app.py"]
