# routes.py
import os
import signal
import sys
import time

from flask import Blueprint, jsonify, request
from source.channel_id import get_channel_id
from source.send_message import send_message

router_get_data_to_sent = Blueprint("router_get_data_to_sent", __name__)


@router_get_data_to_sent.route("/api/sent_data", methods=["POST"])
def send_data():
    data = request.get_json()  # Получите данные из запроса
    response = {"status": "success", "data_received": data}
    print(data)
    status_list = send_message(
        data.get("accounts"),
        data.get("channel_id"),
        data.get("paste"),
        data.get("sleep"),
        data.get("sub"),
        data.get("split"),
    )
    # time.sleep(5)
    # print(status_list)
    # return jsonify({"message": [{'name': 'bot 1', 'status_code': None}, {'name': 'bot 2', 'status_code': 'R9K_MODE'}]})
    return jsonify({"message": status_list})


@router_get_data_to_sent.route("/api/get_data", methods=["GET"])
def get_data_2():
    data = {"message": "Hello from Python backend!"}
    # sys.exit()
    return jsonify(data)


@router_get_data_to_sent.route("/api/get_id", methods=["GET"])
def send_id():
    channel_name = request.args.get("channel_name")
    print(channel_name)
    channel_id = get_channel_id(channel_name)
    return jsonify({"channel_id": channel_id})


@router_get_data_to_sent.route("/shutdown", methods=["GET"])
def shutdown():
    os.kill(os.getpid(), signal.SIGINT)
    return "Server shutting down..."
