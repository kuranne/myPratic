FROM python:latest
WORKDIR /
COPY main.py mykey.py myphone.py requirements.txt /
RUN pip3 install -r requirements.txt
EXPOSE 80
CMD ["python3", "main.py", "app.py" ]