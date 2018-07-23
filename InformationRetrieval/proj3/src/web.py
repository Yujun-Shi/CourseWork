from flask import Flask, request, render_template, redirect, url_for
import Tida

app = Flask(__name__)
app.debug = False


@app.route('/', methods=['GET', 'POST'])
def search():
    if request.method == 'POST':
        sent = request.form['query']
        return redirect(url_for('search_result', sent=sent))
    else:
        return render_template('OnTheBoat.html')


@app.route('/<sent>')
def search_result(sent):
    results = []
    try:
        td = Tida.Tida(False)
        results = td.query(sent)
        print(results)
        if len(results) == 0:
            results.append(['sorry no result matches the query','','',''])
    except Exception as e:
        print(e)
        print(results)
    return render_template('OnTheBoatRes.html', entries = results, sent = sent)


if __name__ == '__main__':
    app.run(host='0.0.0.0', port=3434)
