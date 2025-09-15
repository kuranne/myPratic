FROM python
WORKDIR /kuranne/app
COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt
COPY ./space/app.py .
EXPOSE 5000
CMD ["python", "app.py"]